#include "ticketdata.h"

TicketData::TicketData()
{

}

QDateTime TicketData::datetime() const
{
    return m_datetime;
}

void TicketData::setDatetime(const QDateTime &datetime)
{
    m_datetime = datetime;
}

QString TicketData::displayedName() const
{
    return m_displayedName;
}

void TicketData::setDisplayedName(const QString &displayedName)
{
    m_displayedName = displayedName;
}

QString TicketData::groupAssignment() const
{
    return m_groupAssignment;
}

void TicketData::setGroupAssignment(const QString &groupAssignment)
{
    m_groupAssignment = groupAssignment;
}

QString TicketData::ticket() const
{
    return m_ticket;
}

void TicketData::setTicket(const QString &ticket)
{
    m_ticket = ticket;
}

QString TicketData::numOfWaiting() const
{
    return m_numOfWaiting;
}

void TicketData::setNumOfWaiting(const QString &numOfWaiting)
{
    m_numOfWaiting = numOfWaiting;
}
