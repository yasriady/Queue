#include "mysocket.h"

MySocket::MySocket(const QString &hostName, const quint16 port, QObject *parent)
    : QTcpSocket(parent)
{
    m_hostName = hostName;
    m_port = port;
}

MySocket::~MySocket()
{
}

bool MySocket::connectToHost()
{
    bool connected = false;
    QTcpSocket::connectToHost(m_hostName, m_port);
    if( waitForConnected(1000))
        connected = true;
    return connected;
}

bool MySocket::connectToHost(const QString &hostName, const int &port)
{
    bool connected = false;
    QTcpSocket::connectToHost(hostName, port);
    if( waitForConnected(1000))
        connected = true;
    return connected;
}

bool MySocket::isConnected()
{
    const bool connected = ( state() == QTcpSocket::ConnectedState );
    return connected;
}


