//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef TICKET_H
#define TICKET_H

#include <QFrame>
#include "app_globals.h"
#include <Config>
//#include <QJsonObject>

#define TICKETDIR       APPDIR + SEP + "Ticket" + SEP + TODAY_ + SEP
#define TICKETFILE      TICKET(groupCode, queueNo) + ".pdf"

namespace Ui {
class Ticket;
}

class Ticket : public QFrame
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = 0);
    ~Ticket();

    //void setDB(DB* db);
    void showLastTicket();
    void createNew(const QString &groupCode);

private:
    Ui::Ticket *ui;
    //M_DB;
    QJsonObject m_rcd;
    QString m_template;
    void makeTemplate();
    void updateTicket();

protected:
    virtual void showEvent(QShowEvent *event);

};

#endif // TICKET_H
