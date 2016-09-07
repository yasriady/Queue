#include "ndhelper.h"

NDHelper::NDHelper()
{

}

NDHelper::~NDHelper()
{
}

NodeData NDHelper::dt() const
{
    return m_dt;
}

void NDHelper::setDt(NodeData dt)
{
    m_dt = dt;
}

QString NDHelper::macAddress() const
{
    //return m_macAddress;
    return STRING( m_dt.macAddress );
}

void NDHelper::setMacAddress(const QString &macAddress)
{
    //m_macAddress = macAddress;
    setSTRING( m_dt.macAddress, macAddress );
}

QString NDHelper::nodeName() const
{
    //return m_nodeName;
    return STRING( m_dt.nodeName );
}

void NDHelper::setNodeName(const QString &nodeName)
{
    //m_nodeName = nodeName;
    setSTRING( m_dt.nodeName, nodeName );
}

uint8_t NDHelper::nodeId() const
{
    //return m_nodeId;
    return m_dt.nodeId;
}

void NDHelper::setNodeId(const uint8_t &value)
{
    //m_nodeId = value;
    m_dt.nodeId = value;
}

QString NDHelper::displayedName() const
{
    //return m_displayedName;
    return STRING( m_dt.displayedName );
}

void NDHelper::setDisplayedName(const QString &displayedName)
{
    //m_displayedName = displayedName;
    setSTRING( m_dt.displayedName, displayedName );
}

QString NDHelper::ipAddressClient() const
{
    //return m_ipAddressClient;
    return STRING( m_dt.ipAddressClient );
}

void NDHelper::setIpAddressClient(const QString &ipAddressClient)
{
    //m_ipAddressClient = ipAddressClient;
    setSTRING( m_dt.ipAddressClient, ipAddressClient );
}

QString NDHelper::groupCode() const
{
    //return m_groupCode;
    return STRING( m_dt.groupCode );
}

void NDHelper::setGroupCode(const QString &groupCode)
{
    //m_groupCode = groupCode;
    setSTRING( m_dt.groupCode, groupCode );
    // also need to update queueNo_s
    //this->setQueueNo_s( TICKET( this->groupCode(), this->queueNo() ) );
}

uint8_t NDHelper::portNo() const
{
    //return m_portNo;
    return m_dt.portNo;
}

void NDHelper::setPortNo(const uint8_t &portNo)
{
    //m_portNo = portNo;
    m_dt.portNo = portNo;
}

QString NDHelper::operatorName() const
{
    //return m_opr;
    STRING( m_dt.opr );
}

void NDHelper::setOperatorName(const QString &opr)
{
    //m_opr = opr;
    setSTRING( m_dt.opr, opr );
}

QString NDHelper::service() const
{
    //return m_service;
    return STRING( m_dt.service );
}

void NDHelper::setService(const QString &service)
{
    //m_service = service;
    setSTRING( m_dt.service, service );
}

REQUEST NDHelper::request() const
{
    //return m_request;
    return (REQUEST) m_dt.request;
}

void NDHelper::setRequest(const REQUEST &request)
{
    //m_request = reques;
    m_dt.request = (uint8_t) request;
}

QString NDHelper::requestText() const
{
    //return m_requestText;
    return STRING( m_dt.requestText );
}

void NDHelper::setRequestText(const QString &requestText)
{
    //m_requestText = requestText;
    setSTRING( m_dt.requestText, requestText );
}

uint8_t NDHelper::clientRequest() const
{
    //return m_clientRequest;
    return m_dt.clientRequest;
}

void NDHelper::setClientRequest(const CLIREQUEST &clientRequest)
{
    //m_clientRequest = clientRequest;
    m_dt.clientRequest = clientRequest;
}

QString NDHelper::clientRequestText() const
{
    //return m_clientRequest_s;
    return STRING( m_dt.clientRequest_s );
}

void NDHelper::setClientRequestText(const QString &clientRequest_s)
{
    //m_clientRequest_s = clientRequest_s;
    setSTRING( m_dt.clientRequest_s, clientRequest_s );
}

SRVANSWER NDHelper::serverAnswer() const
{
    //return m_serverAnswer;
    return (SRVANSWER) m_dt.serverAnswer;
}

void NDHelper::setServerAnswer(const SRVANSWER &serverAnswer)
{
    //m_serverAnswer = serverAnswer;
    m_dt.serverAnswer = (uint8_t) serverAnswer;
}

QString NDHelper::serverAnswerText() const
{
    //return m_serverAnswer_s;
    return STRING( m_dt.serverAnswer_s );
}

void NDHelper::setServerAnswerText(const QString &serverAnswer_s)
{
    //m_serverAnswer_s = serverAnswer_s;
    setSTRING( m_dt.serverAnswer_s, serverAnswer_s );
}

uint16_t NDHelper::queueNo() const
{
    //return m_queueNo;
    return m_dt.queueNo;
}

void NDHelper::setQueueNo(const uint16_t &queueNo)
{
    //m_queueNo = queueNo;
    m_dt.queueNo = queueNo;
    // also need to update queueNo_s
    //this->setQueueNo_s( TICKET( this->groupCode(), this->queueNo() ) );
    setSTRING( m_dt.queueNo_s, TICKET( this->groupCode(), this->queueNo() ) );
}

QString NDHelper::queueNoText()
{
    //return m_queueNo_s;
    setSTRING( m_dt.queueNo_s, TICKET( this->groupCode(), this->queueNo() ) );
    return STRING( m_dt.queueNo_s );
}

void NDHelper::setQueueNoText(const QString &queueNo_s)
{
    //m_queueNo_s = queueNo_s;
    //setSTRING( m_dt.queueNo_s, queueNo_s );
}

QString NDHelper::message() const
{
    //return m_message;
    return STRING( m_dt.message );
}

void NDHelper::setMessage(const QString &message)
{
    //m_message_ = m_message;
    setSTRING( m_dt.message, message );
}

bool NDHelper::connected() const
{
    //return m_connected;
    return m_dt.connected;
}

void NDHelper::setConnected(bool connected)
{
    //m_connected = connected;
    m_dt.connected = connected;
}

bool NDHelper::busy() const
{
    //return m_busy;
    return m_dt.busy;
}

void NDHelper::setBusy(bool busy)
{
    //m_busy = busy;
    m_dt.busy = busy;
}

bool NDHelper::RESULT() const
{
    //return m_RESULT;
    return m_dt.RESULT;
}

void NDHelper::setRESULT(bool RESULT)
{
    //m_RESULT = RESULT;
    m_dt.RESULT = RESULT;
}

uint8_t NDHelper::count() const
{
    //return m_count;
    return m_dt.count;
}

void NDHelper::setCount(const uint8_t &count)
{
    //m_count = count;
    m_dt.count = count;
}

uint8_t NDHelper::calledCount() const
{
    //return m_calledCount;
    return m_dt.calledCount;
}

void NDHelper::setCalledCount(const uint8_t &calledCount)
{
    //m_calledCount = calledCount;
    m_dt.calledCount = calledCount;
}

QString NDHelper::dateText() const
{
    //return m_date_s;
    return STRING( m_dt.date_s );
}

void NDHelper::setDateText(const QString &date_s)
{
    //m_date_s = date_s;
    setSTRING( m_dt.date_s, date_s );
}

QString NDHelper::callingTimeText() const
{
    //return m_callingTime_s;
    return STRING( m_dt.callingTime_s );
}

void NDHelper::setCallingTimeText(const QString &callingTime_s)
{
    //m_callingTime_s = callingTime_s;
    setSTRING( m_dt.callingTime_s, callingTime_s );
}

QString NDHelper::processTimeText() const
{
    //return m_processTime_s;
    return STRING( m_dt.processTime_s );
}

void NDHelper::setProcessTimeText(const QString &processTime_s)
{
    //m_processTime_s = processTime_s;
    setSTRING( m_dt.processTime_s, processTime_s );
}

uint16_t NDHelper::numOfWaiting() const
{
    //return m_numOfWaiting;
    return m_dt.numOfWaiting;
}

void NDHelper::setNumOfWaiting(const uint16_t &numOfWaiting)
{
    //m_numOfWaiting = numOfWaiting;
    m_dt.numOfWaiting = numOfWaiting;
}

bool NDHelper::init() const
{
    //return m_init;
    return m_dt.init;
}

void NDHelper::setInit(bool init)
{
    //m_init = init;
    m_dt.init = init;
}

