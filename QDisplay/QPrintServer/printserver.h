//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef PRINTSERVER2_H
#define PRINTSERVER2_H

#include <QObject>
#include "../SharedClass/db.h"
#include <QTcpServer>
#include <QTcpSocket>

class PrintServer : public QObject
{
    Q_OBJECT
public:
    explicit PrintServer(DB* db, QObject *parent = 0);

signals:

public slots:

private:
    DB* m_db;
    QTcpServer *m_server;
    QTcpSocket *m_socket;

private slots:
    void slotNewConnection();
    void slotReadyRead();

};

#endif // PRINTSERVER2_H
