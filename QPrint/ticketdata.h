//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef TICKETDATA_H
#define TICKETDATA_H

#include <QString>
#include <QDateTime>

class TicketData
{
public:
    TicketData();

    QDateTime datetime() const;
    void setDatetime(const QDateTime &datetime);

    QString displayedName() const;
    void setDisplayedName(const QString &displayedName);

    QString groupAssignment() const;
    void setGroupAssignment(const QString &groupAssignment);

    QString ticket() const;
    void setTicket(const QString &ticket);

    QString numOfWaiting() const;
    void setNumOfWaiting(const QString &numOfWaiting);

private:
    QDateTime   m_datetime;
    QString     m_displayedName;
    QString     m_groupAssignment;
    QString     m_ticket;
    QString     m_numOfWaiting;

};

#endif // TICKETDATA_H
