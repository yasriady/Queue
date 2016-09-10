#include "node.h"
#include "ui_node.h"
#include "ui_nodebase.h"

Node::Node(const QString &nodeName, QWidget *parent) :
    NodeBase(parent)
{
    m_nodeName = nodeName;
    setObjectName(m_nodeName);
    //m_db = db;
    //initData();
    customInit(this, nodeName, "", false);
    m_dt = m_dB->getNodeInfoByName2(m_nodeName);
    updateUi(m_dt);

}

Node::~Node()
{
}

//void Node::initData()
//{
//    QJsonObject rcdNode = m_db->getNodeInfoByName( m_nodeName );

//    // fixed
//    m_dt.setMacAddress(                rcdNode["mac_address"]      .toString()             );
//    m_dt.setNodeName(                  rcdNode["node_name"]        .toString()             );
//    m_dt.setNodeId(        (uint8_t)   rcdNode["node_id"]          .toString() .toInt()    );
//    m_dt.setDisplayedName(             rcdNode["displayed_name"]   .toString()             );
//    m_dt.setIpAddressClient(           QString()                                           );  // reserved
//    m_dt.setGroupCode(                 rcdNode["group_code"]       .toString()             );
//    m_dt.setPortNo(        (uint8_t)   rcdNode["port_no"]          .toString() .toInt()    );  // reserved
//    m_dt.setOperatorName(              rcdNode["operator_name"]    .toString()             );
//    m_dt.setService(                   rcdNode["service"]          .toString()             );

//    QJsonObject rcdQueue = m_db->getLastQueue2( m_nodeName );

//    // var
//    m_dt.setRequest(                   REQUEST::INIT                                       );
//    m_dt.setRequestText(               REQUESTTEXT(REQUEST::INIT)                          );  // reserved
//    m_dt.setClientRequest(             CLIREQUEST::CLI_INIT                                );
//    m_dt.setClientRequestText(         QString()                                           );  // reserved
//    m_dt.setServerAnswer(              SRVANSWER::INITOK                                   );  // reserved
//    m_dt.setServerAnswerText(          QString()                                           );  // reserved
//    m_dt.setQueueNo(       (uint16_t)  rcdQueue["queue_no"]         .toString() .toInt()   );
//    m_dt.setQueueNoText(               QString()                                           );  // dummy
//    m_dt.setMessage(                   QString()                                           );  // reserved
//    m_dt.setConnected(                 false                                               );  // reserved
//    m_dt.setBusy(                      false                                               );  // reserved
//    m_dt.setRESULT(                    false                                               );  // reserved
//    m_dt.setCount(         (uint8_t)   0                                                   );  // reserved
//    m_dt.setCalledCount(   (uint8_t)   rcdQueue["called_count"]     .toString() .toInt()   );
//    m_dt.setDateText(                  QString()                                           );  // reserved
//    m_dt.setCallingTimeText(           rcdQueue["calling_time"]     .toString()            );
//    m_dt.setProcessTimeText(           rcdQueue["process_time"]     .toString()            );
//    m_dt.setNumOfWaiting(  (uint16_t)  m_db->getNumOfWaiting(  m_dt.groupCode() )          );
//}

//void Node::updateUi(NDHelper &dt)
//{
//    m_dt.setQueueNo( dt.queueNo() );
//    m_dt.setRequest(dt.request());
//    m_dt.setRequestText( dt.requestText() );

//    ui->displayedName->setText( m_dt.displayedName() );
//    ui->queueNo->setText( m_dt.queueNoText() );

//    // stylesheet
//    QString qssFilename = EXTRADIR + "qss" + SEP  + APPNAME + "_" + m_windowName + "_" + m_dt.requestText() + ".qss";
//    QString styleSheet = "";
//    //qDebug() << qssFilename;
//    if( m_dt.request()==REQUEST::CALLING )
//        styleSheet = textFromFile(qssFilename);
//    setStyleSheet(styleSheet);

//}

