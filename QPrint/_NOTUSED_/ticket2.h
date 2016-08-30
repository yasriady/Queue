#ifndef TICKET2_H
#define TICKET2_H

#include <QObject>
#include "../db.h"

class Ticket2 : public QObject
{
    Q_OBJECT
public:
    explicit Ticket2(QObject *parent = 0, DB* db = 0);

    void makeTicket(const QString &groupCode);
    void showLastTicket();

signals:

public slots:

private:
    DB *m_db;
};

#endif // TICKET2_H
