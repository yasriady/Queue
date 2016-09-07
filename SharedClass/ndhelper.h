//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef NDHELPER_H
#define NDHELPER_H

#include <QObject>
#include <QString>
#include "../SharedClass/config.h"

//#define DT                          m_dt->dt()
//#define TICKET(groupCode, queueNo)  QString( "%1-%2" ).arg(groupCode).arg(queueNo)

class NDHelper
{
public:
    NDHelper();
    ~NDHelper();

    NodeData dt() const;
    void setDt(NodeData dt);

    QString macAddress() const;
    void setMacAddress(const QString &macAddress);

    QString nodeName() const;
    void setNodeName(const QString &nodeName);

    uint8_t nodeId() const;
    void setNodeId(const uint8_t &value);

    QString displayedName() const;
    void setDisplayedName(const QString &displayedName);

    QString ipAddressClient() const;
    void setIpAddressClient(const QString &ipAddressClient);

    QString groupCode() const;
    void setGroupCode(const QString &groupCode);

    uint8_t portNo() const;
    void setPortNo(const uint8_t &portNo);

    QString operatorName() const;
    void setOperatorName(const QString &opr);

    QString service() const;
    void setService(const QString &service);

    REQUEST request() const;
    void setRequest(const REQUEST &request);

    QString requestText() const;
    void setRequestText(const QString &requestText);

    uint8_t clientRequest() const;
    void setClientRequest(const CLIREQUEST &clientRequest);

    QString clientRequestText() const;
    void setClientRequestText(const QString &clientRequest_s);

    SRVANSWER serverAnswer() const;
    void setServerAnswer(const SRVANSWER &serverAnswer);

    QString serverAnswerText() const;
    void setServerAnswerText(const QString &serverAnswer_s);

    uint16_t queueNo() const;
    void setQueueNo(const uint16_t &queueNo);

    QString queueNoText();
    void setQueueNoText(const QString &queueNoText);

    QString message() const;
    void setMessage(const QString &message);

    bool connected() const;
    void setConnected(bool connected);

    bool busy() const;
    void setBusy(bool busy);

    bool RESULT() const;
    void setRESULT(bool RESULT);

    uint8_t count() const;
    void setCount(const uint8_t &count);

    uint8_t calledCount() const;
    void setCalledCount(const uint8_t &calledCount);

    QString dateText() const;
    void setDateText(const QString &date_s);

    QString callingTimeText() const;
    void setCallingTimeText(const QString &callingTime_s);

    QString processTimeText() const;
    void setProcessTimeText(const QString &processTime_s);

    uint16_t numOfWaiting() const;
    void setNumOfWaiting(const uint16_t &numOfWaiting);

    bool init() const;
    void setInit(bool init);

private:

    NodeData m_dt;

    //    // fixed
    //    QString         m_macAddress;
//    QString         m_nodeName;
//    uint8_t         m_nodeId;
//    QString         m_displayedName;
//    QString         m_ipAddressClient;
//    QString         m_groupCode;
//    uint8_t         m_portNo;
//    QString         m_opr;
//    QString         m_service;
//    // var
//    uint8_t         m_request;        //               = (uint8_t)REQUEST::INIT;          //
//    char[12]        m_requestText;
//    uint8_t         m_clientRequest;//              = (uint8_t)CLIREQUEST::CLI_INIT;          //
//    QString         m_clientRequest_s;
//    uint8_t         m_serverAnswer;
//    QString         m_serverAnswer_s;
//    uint16_t        m_queueNo;
//    QString         m_queueNo_s;
//    QString         m_message;
//    bool            m_connected;
//    bool            m_busy;
//    // reserved
//    bool            m_RESULT;
//    uint8_t         m_count;
//    uint8_t         m_calledCount;
//    QString         m_date_s;
//    QString         m_callingTime_s;
//    QString         m_processTime_s;
//    uint16_t        m_numOfWaiting;
//    bool                m_init;

};

#endif // NDHELPER_H
