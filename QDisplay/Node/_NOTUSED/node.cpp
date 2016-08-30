#include "node.h"
#include "ui_node.h"

Node::Node(const QString &objName, DB *db, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Node)
{
    ui->setupUi(this);
    m_db = db;
    setObjectName(objName);
    setSizePolicy(QSizePolicy::Ignored , QSizePolicy::Expanding);

}

Node::Node(QWidget *parent)
    : QFrame(parent)
{

}

Node::~Node()
{
    delete ui;
}

void Node::showEvent(QShowEvent *event)
{
    ui->frame_1->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->opr->hide();
    ui->service->hide();

    initVar();
    updateUi();
    m_bigNode->resetUi();

    QFrame::showEvent(event);
}

void Node::initVar()
{
    //    QString nodeName        = objectName();

    //    MyMap rcd = m_db->getQueueNo(nodeName);

    //    CLIREQUEST  action    = (CLIREQUEST) m_dt.clientAction;
    //    //QString nodeName        = objectName();
    //    QString macAddress      = m_db->getMacAddress(nodeName);
    //    uint16_t queueNo         = rcd["queue_no"].toInt();
    //    uint8_t nodeId          = m_db->getNodeId(nodeName);
    //    QString displayedName   = m_db->getDisplayedName(nodeName);
    //    QString ipAddressClient = "?";
    //    QString groupCode       = m_db->getGroupCode(nodeName);
    //    QString status          = rcd["status_desc"].toString();
    //    //status = (status=="ONCALL") ? "Call" : ( (status=="PROCESS") ? "PROCESS" : "" );
    //    QString message         = "restarted";
    //    uint8_t portNo          = (uint8_t) m_db->getPortNo(nodeName);
    //    bool    connected       = m_dt.connected;
    //    bool    busy            = m_dt.busy;
    //    bool    RESULT          = m_dt.RESULT;
    //    uint8_t count           = m_dt.count;
    //    // added, 2016-08-17, NOT FINISHED YET
    //    QString opr             = m_db->getOpr(nodeName);
    //    uint8_t calledCount     = -9;
    //    QString groupAssignment = m_db->getGroupAssignment(groupCode);
    //    QString date_           = CURDATETIME_;
    //    QString callingTime_    = (m_dt.calledCount == 2) ? m_dt.callingTime : CURDATETIME_;
    //    QString processTime_    = CURDATETIME_;

    //    m_dt.clientAction = action;
    //    strncpy( m_dt.macAddress, macAddress.toUtf8(), sizeof(m_dt.macAddress)-1 );
    //    m_dt.nodeId = nodeId;
    //    strncpy( m_dt.nodeName, nodeName.toUtf8(), sizeof(m_dt.nodeName)-1 );
    //    strncpy( m_dt.displayedName, displayedName.toUtf8(), sizeof(m_dt.displayedName)-1 );
    //    m_dt.queueNo = queueNo;
    //    strncpy( m_dt.ipAddressClient, ipAddressClient.toUtf8(), sizeof(m_dt.ipAddressClient)-1 );
    //    strncpy( m_dt.groupCode, groupCode.toUtf8(), sizeof(m_dt.groupCode)-1 );
    //    strncpy( m_dt.clientAction_, status.toUtf8(), sizeof(m_dt.clientAction_)-1 );
    //    strncpy( m_dt.message, message.toUtf8(), sizeof(m_dt.message)-1 );
    //    m_dt.portNo = portNo;
    //    m_dt.connected = connected;
    //    m_dt.busy = busy;
    //    m_dt.RESULT = RESULT;
    //    m_dt.count = count;
    //    // added, 2016-08-17, NOT FINISHED YET
    //    strncpy( m_dt.opr, opr.toUtf8(), sizeof(m_dt.opr)-1 );
    //    //m_dt.calledCount = rcd["called_count"].toInt();
    //    strncpy( m_dt.service, groupAssignment.toUtf8(), sizeof(m_dt.service)-1 );
    //    strncpy( m_dt.date, date_.toUtf8(), sizeof(m_dt.date)-1 );
    //    strncpy( m_dt.callingTime, callingTime_.toUtf8(), sizeof(m_dt.callingTime)-1 );
    //    strncpy( m_dt.processTime, processTime_.toUtf8(), sizeof(m_dt.processTime)-1 );

    const QString &nodeName = objectName();
    const QString &macAddress = m_db->getMacAddress(nodeName);
    strncpy( m_dt.macAddress, macAddress.toUtf8(), sizeof(m_dt.macAddress) );
    strncpy( m_dt.nodeName, nodeName.toUtf8(), sizeof(m_dt.nodeName) );
    ClassHelper h(&m_dt, m_db);

}

void Node::clientConnected(NodeData &nodeData, Socket *tcpSocket)
{
    m_dt = nodeData;
    ClassHelper h(&m_dt, m_db);
    MyMap rcd;

    // LOGIN, CALL, PROCESS, PING, NONE
    switch ( m_dt.clientRequest ) {

    case CLIREQUEST::CLI_LOGIN :
        emit signalLog( "Client LOGIN from " + QString(m_dt.macAddress) );
        //message = "LOGIN";
        //status = "???";
        rcd = m_db->doLogin( m_dt.nodeName );
        break;

    case CLIREQUEST::CLI_CALLING :
        emit signalLog( "Client CALL from " + QString(m_dt.macAddress) );
        //message = "CALL";
        rcd = m_db->doCalling( m_dt.nodeName );
        //callingTime_ = rcd["calling_time"].toString() ;
        //h.A( m_dt.callingTime, rcd["calling_time"].toString() );
        m_dt.serverAnswer = SRVANSWER::CALL_OK;
        break;

    case CLIREQUEST::CLI_PROCESS :
        emit signalLog( "Client do PROCESS : " + QString(m_dt.macAddress) );
        //message = "PROCESS";
        rcd = m_db->doProcess( m_dt.nodeName );
        //processTime_ = rcd["process_time"].toString() ;
        //h.A( m_dt.processTime, rcd["process_time"].toString() );
        m_dt.serverAnswer = SRVANSWER::PROCESS_OK;
        break;

    case CLIREQUEST::CLI_PING :
        emit signalLog( "Client PING from " + QString(m_dt.macAddress) );
        //message = "PING";
        rcd = m_db->doPing( m_dt.nodeName );
        break;
    default:
        break;
    }

    h.A( m_dt.numOfWaiting, m_db->getNumOfWaiting( QString(m_dt.groupCode) ) );
    h.A( m_dt.queueNo,      rcd["queue_no"].toInt() );
    h.A( m_dt.calledCount,  rcd["called_count"].toInt() );

    //    QString service;
    //    service = rcd["service"].toString();
    //    h.A( m_dt.service,      service, sizeof(m_dt.service) );
    h.A( m_dt.date_s,         m_dt.date_s, sizeof( m_dt.date_s ) );
    h.A( m_dt.callingTime_s,  h.S( rcd["calling_time"] ), sizeof( m_dt.callingTime_s ) );
    h.A( m_dt.processTime_s,  h.S( rcd["process_time"] ), sizeof( m_dt.processTime_s ) );

    updateUi();
    tcpSocket->write( (char*)&m_dt, sizeof(m_dt) );
    nodeData = m_dt;    // data returned

}

void Node::updateUi()
{
    mkCONFIX;
    QString status = tr(m_dt.clientRequest_s);
    status = status.trimmed();

    QString numOfWaiting_ = QString::number(m_dt.numOfWaiting, 10);
    QString dateTime_;
    QString styleSheet;
    QString calledCount  = "";

    //    if( status == CALLING_ )
    //    {
    //        status += QString(" (%1x)   ").arg(m_dt.calledCount);
    //        styleSheet = confx->string( KEY("callingStyleSheet"), "" );
    //        dateTime_ = (tr(m_dt.callingTime)).right(8);

    //    }
    //    if( status == PROCESS_ )
    //    {
    //        styleSheet = confx->string( KEY("processStyleSheet"), "" );
    //        dateTime_ = (tr(m_dt.processTime)).right(8);
    //    }

    if( QString::fromUtf8(m_dt.nodeName) == "NODE_07" )
    {
        __PF__;
    }

    switch (m_dt.clientRequest) {

    case CLIREQUEST::CLI_INIT:
        status = tr(m_dt.clientRequest_s);
        dateTime_ = (tr(m_dt.callingTime_s)).right(8);
        break;

    case CLIREQUEST::CLI_CALLING:
        //status = QString("   %1    ").arg(status);
        status = "    CALLING    ";
        calledCount = QString("%1x").arg( m_dt.calledCount );
        styleSheet = confx->string( KEY("callingStyleSheet"), "" );
        dateTime_ = (tr(m_dt.callingTime_s)).right(8);
        break;

    case CLIREQUEST::CLI_PROCESS:
        styleSheet = confx->string( KEY("processStyleSheet"), "" );
        dateTime_ = (tr(m_dt.processTime_s)).right(8);
        break;

    default:
        break;
    }


    const QString &groupCode = tr( m_dt.groupCode );
    const int &queueNo = m_dt.queueNo;


    ui->status->setText( status );
    ui->status->stopRunningText();
    if( m_dt.clientRequest  == CLIREQUEST::CLI_CALLING )
    {
        ui->status->startRunningText();
    }
    ui->calledCount->setText( calledCount  );
    ui->queueNo->setText( TICKET(groupCode, queueNo) );
    ui->displayedName->setText( tr(m_dt.displayedName) );
    ui->connected->setPixmap( makePixmap(m_dt.connected) );
    ui->message->setText( tr(m_dt.message) );
    ui->groupCode->setText( tr(m_dt.groupCode) );
    ui->nodeName->setText( tr(m_dt.nodeName) );
    ui->macAddress->setText( tr(m_dt.macAddress) );
    //ui->rowid->setText( tr(m_dt.opr) );
    ui->service->setText( tr(m_dt.service) );
    ui->dateTime->setText( dateTime_ );
    ui->numOfWaiting->setText(numOfWaiting_);
    ui->opr->setText( m_dt.opr );

    // styling ...
    ui->queueNo->setStyleSheet(styleSheet);

    m_bigNode->updateUi(&m_dt);
}

const QPixmap Node::makePixmap(const bool &connected)
{
    QString pngDisconnected = QString::fromUtf8(":/icon/png_16/process-stop.png");
    QString pngConnected    = QString::fromUtf8(":/icon/png_16/checkbox.png");
    QString png             = connected ? pngConnected : pngDisconnected;
    const QPixmap &pixmap = QPixmap(png);
    return pixmap;
}

void Node::setBigNode(BigNode *bigNode)
{
    m_bigNode = bigNode;
}

