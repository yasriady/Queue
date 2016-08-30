#include "nodea.h"
#include "ui_nodea.h"

//NodeA::NodeA(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::NodeA)
//{
//    ui->setupUi(this);
//}

NodeA::NodeA(const QString &objName, DB *db, QWidget *parent)
    :    DWidget(parent),
      ui(new Ui::NodeA)
{
    ui->setupUi(this);
    init();

    m_db = db;
    setObjectName(objName);

    QJsonObject rcdNode = m_db->getNodeInfoByName( nodeName() );

    // fixed
    m_dt.setMacAddress(                rcdNode["mac_address"]      .toString()             );
    m_dt.setNodeName(                  rcdNode["node_name"]        .toString()             );
    m_dt.setNodeId(        (uint8_t)   rcdNode["node_id"]          .toString() .toInt()    );
    m_dt.setDisplayedName(             rcdNode["displayed_name"]   .toString()             );
    m_dt.setIpAddressClient(           QString()                                           );  // reserved
    m_dt.setGroupCode(                 rcdNode["group_code"]       .toString()             );
    m_dt.setPortNo(        (uint8_t)   rcdNode["port_no"]          .toString() .toInt()    );  // reserved
    m_dt.setOperatorName(              rcdNode["operator_name"]    .toString()             );
    m_dt.setService(                   rcdNode["service"]          .toString()             );

    QJsonObject rcdQueue = m_db->getLastQueue2( nodeName() );

    // var
    m_dt.setRequest(                   REQUEST::INIT                                       );
    m_dt.setRequestText(               REQUESTTEXT(REQUEST::INIT)                          );  // reserved
    m_dt.setClientRequest(             CLIREQUEST::CLI_INIT                                );
    m_dt.setClientRequestText(         QString()                                           );  // reserved
    m_dt.setServerAnswer(              SRVANSWER::INITOK                                   );  // reserved
    m_dt.setServerAnswerText(          QString()                                           );  // reserved
    m_dt.setQueueNo(       (uint16_t)  rcdQueue["queue_no"]         .toString() .toInt()   );
    m_dt.setQueueNoText(               QString()                                           );  // dummy
    m_dt.setMessage(                   QString()                                           );  // reserved
    m_dt.setConnected(                 false                                               );  // reserved
    m_dt.setBusy(                      false                                               );  // reserved
    m_dt.setRESULT(                    false                                               );  // reserved
    m_dt.setCount(         (uint8_t)   0                                                   );  // reserved
    m_dt.setCalledCount(   (uint8_t)   rcdQueue["called_count"]     .toString() .toInt()   );
    m_dt.setDateText(                  QString()                                           );  // reserved
    m_dt.setCallingTimeText(           rcdQueue["calling_time"]     .toString()            );
    m_dt.setProcessTimeText(           rcdQueue["process_time"]     .toString()            );
    m_dt.setNumOfWaiting(  (uint16_t)  m_db->getNumOfWaiting(  m_dt.groupCode() )          );

    updateUi();
}

NodeA::~NodeA()
{
    delete ui;
}

NDHelper NodeA::clientConnected(const RDHelper &rd)
{
    QJsonObject rcd;
    MyMap rcd2;

    REQUEST request = rd.request();
    m_dt.setRequest( request );

    switch ( request ) {

    case REQUEST::INIT:
        rcd = m_db->getLastQueue2( nodeName() );
        if( rcd["status"].toString().toInt()==1 ) request = REQUEST::CALLING;
        if( rcd["status"].toString().toInt()==2 ) request = REQUEST::PROCESS;
        m_dt.setQueueNo( (uint16_t) rcd["queue_no"].toString().toInt() );
        break;

    case REQUEST::LOGIN :
        //emit signalLog( "Client LOGIN from " + QString(m_dt.macAddress) );
        //rcd = m_db->doLogin( m_dt.nodeName );
        break;

    case REQUEST::CALLING :
        //emit signalLog( "Client CALL from " + QString(m_dt.macAddress) );
        rcd2 = m_db->doCalling( nodeName() );
        m_dt.setQueueNo( rcd2["queue_no"].toInt() );
        m_dt.setCallingTimeText( rcd2["calling_time"].toString() );
        m_dt.setCalledCount( rcd2["called_count"].toString().toInt()  );
        break;

    case REQUEST::PROCESS :
        //emit signalLog( "Client do PROCESS : " + QString(m_dt.macAddress) );
        rcd2 = m_db->doProcess( nodeName() );
        m_dt.setQueueNo( rcd2["queue_no"].toInt() );
        m_dt.setProcessTimeText( rcd2["process_time"].toString() );
        m_dt.setNumOfWaiting( m_db->getNumOfWaiting( m_dt.groupCode() ) );
        break;

    case REQUEST::PING :
        //emit signalLog( "Client PING from " + QString(m_dt.macAddress) );
        //rcd = m_db->doPing( m_dt.nodeName );
        break;
    default:
        break;
    }

    m_dt.setRequest(request);
    m_dt.setServerAnswer(SRVANSWER::REQUESTOK);
    m_dt.setRequestText( REQUESTTEXT(request) );

    updateUi();
    return m_dt;
}

void NodeA::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
}

void NodeA::updateUi()
{
    ui->queueNo->setText( m_dt.queueNoText() );
    ui->displayedName->setText( m_dt.displayedName() );

    // stylesheet
    QString qssFilename = EXTRADIR + APPNAME + "_" + m_windowName + "_" + m_dt.requestText() + ".qss";
    QString styleSheet = "";
    if( m_dt.request()==REQUEST::CALLING )
        styleSheet = textFromFile(qssFilename);
    setStyleSheet(styleSheet);
}

const QString NodeA::nodeName()
{
    return objectName();
}

