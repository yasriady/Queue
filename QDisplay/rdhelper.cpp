#include "rdhelper.h"

RDHelper::RDHelper()
{
    m_rd = new RequestData();
}

RDHelper::~RDHelper()
{
    delete m_rd;
}

QString RDHelper::macAddress() const
{
    //return m_macAddress;
    return STRING( m_rd->macAddress );
}

void RDHelper::setMacAddress(const QString &macAddress)
{
    //m_macAddress = macAddress;
    setSTRING( m_rd->macAddress, macAddress );
}

REQUEST RDHelper::request() const
{
    //return m_clientRequest;
    return (REQUEST) m_rd->request;
}

void RDHelper::setRequest(const REQUEST &request)
{
    //m_clientRequest = clientRequest;
    m_rd->request = (uint8_t) request;
}

RequestData *RDHelper::rd() const
{
    return m_rd;
}

void RDHelper::setRd(RequestData *rd)
{
    m_rd = rd;
}
