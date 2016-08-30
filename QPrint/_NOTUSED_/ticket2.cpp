#include "ticket2.h"

Ticket2::Ticket2(QObject *parent, DB *db) : QObject(parent)
{
    m_db = db;
}

void Ticket2::makeTicket(const QString &groupCode)
{

}

void Ticket2::showLastTicket()
{
    QJsonObject rcd = m_db->getLastPrintedQueue();
}
