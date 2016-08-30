#include "printserver.h"

PrintServer::PrintServer(DB *db, QObject *parent) : QObject(parent)
{
    m_db = db;
    m_server = new QTcpServer(this);
    if( !m_server->listen(QHostAddress::AnyIPv4, 8999) )
    {
        //slotLogger("server listen error!");
        return;
    } else {
        //slotLogger("server listen OK!");
    }
    connect( m_server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );
}

void PrintServer::slotNewConnection()
{
    //if( _busy ) return;
    m_socket = (QTcpSocket*) m_server->nextPendingConnection();
    //const QHostAddress &peerAddress = m_tcpSocket->peerAddress();
    //LOGGER("New connection from: " + peerAddress.toString() );
    connect( m_socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );
}

void PrintServer::slotReadyRead()
{
    //m_socket->read()

}
