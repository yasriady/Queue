#ifndef TICKET_H
#define TICKET_H

#include <QWidget>
#include "../db.h"
#include "ticketdata.h"
#include <DSettings/dsettings.h>

namespace Ui {
class Ticket;
}

class Ticket : public QWidget
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = 0);
    ~Ticket();

private:
    Ui::Ticket *ui;
    DB* m_db;
    TicketData *m_dt;

    QDateTime   m_dateTime;
    QString     m_displayedName;
    QString     m_groupAssignment;
    QString     m_ticket;
    int         m_numOfWaiting;

    void makeHeader();

protected:
    virtual void showEvent(QShowEvent *event);

public:
    void setDB(DB *db);
    void showLastTicket();
    QString makeTicket(const QString &groupCode);
    void updateTicket(const QString &groupCode, const int &queueNo);

};

#endif // TICKET_H
