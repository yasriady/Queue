//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>

class MySocket : public QTcpSocket
{
public:
    explicit MySocket(const QString &hostName, const quint16 port, QObject *parent = Q_NULLPTR);
    virtual ~MySocket();

private:
    QString m_hostName;
    quint16 m_port;

public:
    bool connectToHost();
    bool connectToHost(const QString &hostName, const int &port);
    bool isConnected();

};

#endif // MYSOCKET_H
