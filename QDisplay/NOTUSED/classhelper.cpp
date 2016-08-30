#include "classhelper.h"

ClassHelper::ClassHelper(NodeData *dt, DB *db)
{
    m_dt = dt;
    m_db = db;

    const QString &nodeName = QString::fromUtf8(m_dt->nodeName);
    //const QString &macAddress = QString::fromUtf8(m_dt->macAddress);
    const QString &sql = QString( " SELECT * FROM v_PrintedQueue WHERE processed_by='%1' AND rowidx=(SELECT MAX(rowidx) FROM v_PrintedQueue WHERE processed_by='%1')  " ).arg(nodeName);

    const QJsonObject &rcd = m_db->getNodeInfo( m_dt->macAddress );

//    A( m_dt->macAddress_,       m_dt->macAddress_, sizeof(m_dt->macAddress_) );
//    A( m_dt->nodeName_,         m_db->getNodeName( m_dt->macAddress_ ), sizeof(m_dt->nodeName_) );
//    A( m_dt->nodeId,           m_db->getNodeId( m_dt->nodeName_ ) );
//    A( m_dt->clientRequest,    m_dt->clientRequest );
//    A( m_dt->clientRequest_,   m_dt->clientRequest_, sizeof(m_dt->clientRequest_) );
//    A( m_dt->displayedName_,    m_db->getDisplayedName( m_dt->nodeName_ ), sizeof(m_dt->displayedName_) );
//    A( m_dt->queueNo,          m_dt->queueNo );
//    A( m_dt->queueNo_,         m_dt->queueNo_, sizeof(m_dt->queueNo_) );
//    A( m_dt->ipAddressClient_,  m_dt->ipAddressClient_, sizeof(m_dt->ipAddressClient_) );
//    A( m_dt->groupCode_,        m_db->getGroupCode( m_dt->nodeName_ ), sizeof(m_dt->groupCode_) );        // pindah ke atas
//    A( m_dt->message,          m_dt->message, sizeof(m_dt->message) );
//    A( m_dt->portNo,           m_dt->portNo );
//    A( m_dt->connected,        m_dt->connected );
//    A( m_dt->busy,             m_dt->busy );
//    A( m_dt->RESULT,           m_dt->RESULT );
//    A( m_dt->count,            m_dt->count );
//    A( m_dt->opr_,              m_db->getOpr( m_dt->nodeName_ ), sizeof(m_dt->opr_) );
//    A( m_dt->calledCount,      m_dt->calledCount );
//    A( m_dt->service_,          m_db->getService(m_dt->groupCode_), sizeof(m_dt->service_) );
//    A( m_dt->date_,             CURDATE_, sizeof(m_dt->date_) );
//    A( m_dt->callingTime_,      m_dt->callingTime_, sizeof(m_dt->callingTime_) ); //m_db->getLastlCallingTime(nodeName)
//    A( m_dt->processTime_,      m_dt->processTime_, sizeof(m_dt->processTime_) );
//    A( m_dt->numOfWaiting,     m_db->getNumOfWaiting( m_dt->groupCode_ ) );


    A( m_dt->macAddress,       m_dt->macAddress, sizeof(m_dt->macAddress) );
    A( m_dt->nodeName,         rcd["node_name"].toString(), sizeof(m_dt->nodeName) );
    A( m_dt->nodeId,           (rcd["node_id"].toString()).toInt() );
    A( m_dt->clientRequest,    m_dt->clientRequest );
    A( m_dt->clientRequest_s,   m_dt->clientRequest_s, sizeof(m_dt->clientRequest_s) );
    A( m_dt->displayedName,    rcd["displayed_name"].toString() , sizeof(m_dt->displayedName) );
    A( m_dt->queueNo,          m_dt->queueNo );
    A( m_dt->queueNo_s,         m_dt->queueNo_s, sizeof(m_dt->queueNo_s) );
    A( m_dt->ipAddressClient,  m_dt->ipAddressClient, sizeof(m_dt->ipAddressClient) );
    A( m_dt->groupCode,        rcd["group_code"].toString() , sizeof(m_dt->groupCode) );        // pindah ke atas
    A( m_dt->message,          m_dt->message, sizeof(m_dt->message) );
    A( m_dt->portNo,           m_dt->portNo );
    A( m_dt->connected,        m_dt->connected );
    A( m_dt->busy,             m_dt->busy );
    A( m_dt->RESULT,           m_dt->RESULT );
    A( m_dt->count,            m_dt->count );
    A( m_dt->opr,             rcd["operator_name"].toString()  , sizeof(m_dt->opr) );
    A( m_dt->calledCount,      m_dt->calledCount );
    A( m_dt->service,         rcd["service"].toString()  , sizeof(m_dt->service) );
    A( m_dt->date_s,             CURDATE_, sizeof(m_dt->date_s) );
    A( m_dt->callingTime_s,      m_dt->callingTime_s, sizeof(m_dt->callingTime_s) ); //m_db->getLastlCallingTime(nodeName)
    A( m_dt->processTime_s,      m_dt->processTime_s, sizeof(m_dt->processTime_s) );
    A( m_dt->numOfWaiting,     m_db->getNumOfWaiting( m_dt->groupCode ) );

}

void ClassHelper::A(char *param, QString value, size_t size)
{
    strncpy( param, value.toUtf8(), size-0 );
}

void ClassHelper::A(uint16_t &param, uint16_t value)
{
    param = value;
}

void ClassHelper::A(uint8_t &param, uint8_t value)
{
    param = value;
}

void ClassHelper::A(bool &param, bool value)
{
    param = value;
}

const QString ClassHelper::S(const QVariant &var)
{
    const QString &ret = var.toString();
    return ret;
}
