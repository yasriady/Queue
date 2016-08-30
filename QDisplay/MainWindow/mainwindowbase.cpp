#include "mainwindowbase.h"

MainWindowBase::MainWindowBase(QWidget *parent, Qt::WindowFlags flags)
    : DMainWindow(parent)
{
    m_busy = false;
    m_init = true;
    m_db = new DB();
    m_callerSound = new DCallerSound(this);
    connect( m_callerSound, SIGNAL(signalSoundFinish()), this, SLOT(slotSoundFinish()) );

    m_tcpServer = new Server(this);
    if( !m_tcpServer->listen(QHostAddress::AnyIPv4, SERVER_PORT) )
    {
        //slotLogger("server listen error!");
        return;
    } else {
        //slotLogger("server listen OK!");
    }
    connect( m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );

}

MainWindowBase::~MainWindowBase()
{
    delete m_callerSound;
    delete m_db;

}

void MainWindowBase::makeSound(const NDHelper &dt)
{
    QStringList strList;

    if( m_init || (dt.queueNo()==0) )
    {
        slotSoundFinish();
        return;
    }

    switch ( m_dt.request() ) {

    case REQUEST::CALLING:
        strList = NumericConverter2( (int)dt.queueNo() );
        strList.insert(0, QString(dt.groupCode()).toLower() );
        strList.insert(0, "nomor-urut");
        strList.insert(0, "Ding-dong_C");
        strList.append("di-loket");
        strList.append((NumericConverter1((int)dt.nodeId())).trimmed());
        break;

    case REQUEST::PROCESS:
        strList << "chime";
        m_callerSound->call(strList);
        break;

    default:
        break;
    }

    m_callerSound->call( strList );

}

void MainWindowBase::makeNodes(QGridLayout* layout, BigNode *bigNode)
{
    //    QGridLayout *gridLayout1 = layout; // (QGridLayout*)ui->nodes->layout(); //new QGridLayout(ui->frame_2);
    //    QGridLayout *gridLayout2 = new QGridLayout();
    //    const int nodeQty = 10;
    //    int colNum = 5;
    //    int rowNum = (int) (nodeQty / colNum);
    //    int nodeIdx= 0;
    //    for(int row = 1; row <= rowNum; row++) {
    //        for(int col = 1; col <= colNum; col++) {
    //            QString nodeName = QString(QString::number(++nodeIdx).rightJustified(2, '0'));
    //            nodeName.insert(0, "NODE_");
    //            Node *node = new Node(nodeName, m_db, this);
    //            connect( node, SIGNAL(signalLog(QString)), this, SLOT(slotLogger(QString)) );
    //            gridLayout2->addWidget(node, row, col);
    //            //node->setBigNode(bigNode);
    //        }
    //    }
    //    gridLayout1->addLayout(gridLayout2, rowNum, colNum);

}

void MainWindowBase::makeNodesA(QFrame *frame, BigNode *bigNode)
{
    QVBoxLayout *layout1 = (QVBoxLayout*)frame->layout();
    QGridLayout *layout2 = new QGridLayout();
    const int nodeQty = 10;
    int colNum = 5;
    int rowNum = (int) (nodeQty / colNum);
    int nodeIdx= 0;
    for(int row = 1; row <= rowNum; row++) {
        for(int col = 1; col <= colNum; col++) {
            QString nodeName = QString(QString::number(++nodeIdx).rightJustified(2, '0'));
            nodeName.insert(0, "NODE_");
            NodeA *node = new NodeA(nodeName, m_db, this);
            connect( node, SIGNAL(signalLog(QString)), this, SLOT(slotLogger(QString)) );
            layout2->addWidget(node, row, col);
        }
    }
    layout1->addLayout(layout2, 1);
    m_bigNode = bigNode;

}

void MainWindowBase::slotSoundFinish()
{
    __PF__;
    m_busy = false;
}

void MainWindowBase::slotNewConnection()
{
    if( m_busy )
    {
        __PF("Busy men ..!");
        //m_tcpServer->nextPendingConnection()->close();
        NDHelper dt;
        dt.setServerAnswer(SRVANSWER::SRVBUSY);
        m_msg = m_db->getTaxonomy(ERR_SRVBUSY, 0);
        dt.setMessage(m_msg);
        NodeData d = dt.dt();
        Socket *tcpSocket = (Socket*) m_tcpServer->nextPendingConnection();
        tcpSocket->write( (char*)&d, sizeof(d) );
        tcpSocket->close();
        return;
    }

    m_tcpSocket = (Socket*) m_tcpServer->nextPendingConnection();
    //    const QHostAddress &peerAddress = m_tcpSocket->peerAddress();
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );
}

void MainWindowBase::slotReadyRead()
{
    //m_tcpSocket->read( (char*)&m_dt, sizeof(m_dt) );

    RequestData *rd = m_rd.rd();
    m_tcpSocket->read( (char*)rd, sizeof(*rd) );

    QString macAddress = m_rd.macAddress();
    QString nodeName = m_db->getNodeName(macAddress);

    if( nodeName == NOTFOUND ) {
        LOGGER( "Node with mac address "+ macAddress +" not registered" );
        NDHelper dt;
        dt.setServerAnswer(SRVANSWER::NOTREGISTERED);
        m_msg = m_db->getTaxonomy( ERR_NOTREGISTERED, 0 );
        dt.setMessage(m_msg);
        NodeData d = dt.dt();
        m_tcpSocket->write( (char*)&d, sizeof(d) );
        m_tcpSocket->close();
        return;
    }

    NodeA *node = findChild<NodeA*>(nodeName);
    if( !node ) {
        LOGGER("Node object is not exist");
        return;
    }

    // OK, client is valid ...

    m_init = false;
    if( m_rd.request()==INIT )
        m_init = true;

    m_busy = true;
    m_dt = node->clientConnected(m_rd);
    NodeData dt = m_dt.dt();
    m_tcpSocket->write( (char*)&dt, sizeof(dt) );
    m_bigNode->updateUi(&m_dt);

    makeSound(m_dt);

}
