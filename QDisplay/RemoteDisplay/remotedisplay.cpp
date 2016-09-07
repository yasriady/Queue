#include "remotedisplay.h"

RemoteDisplay::RemoteDisplay(QObject *parent) : QObject(parent)
{
    m_tcpServer = new Server(this);
    mkCONFIG;
    if( !m_tcpServer->listen(QHostAddress::AnyIPv4, REMOTEDISPLAYPORT) )
    {
        //slotLogger("server listen error!");
        return;
    } else {
        //slotLogger("server listen OK!");
    }
    connect( m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );

}

RemoteDisplay::~RemoteDisplay()
{
    delete m_tcpServer;
}

void RemoteDisplay::slotNewConnection()
{
    QTcpSocket* client = (QTcpSocket*)m_tcpServer->nextPendingConnection();
    m_clientList[client] = client;
    connect( client, SIGNAL(disconnected()), this, SLOT(slotSocketDisconnected()) );
    //qDebug() << "Jumlah client: " << m_clientList.size();
    m_statusBarWidget->setLabel1( QString("Remote: %1").arg(m_clientList.size()) );
}

void RemoteDisplay::slotSocketError(QAbstractSocket::SocketError error)
{
    //__PF__;
}

void RemoteDisplay::slotSocketDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    disconnect( client, SIGNAL(disconnected()) );
    m_clientList.remove(client);
    //qDebug() << "Jumlah client: " << m_clientList.size();
    m_statusBarWidget->setLabel1( QString("Remote: %1").arg(m_clientList.size()) );
}

void RemoteDisplay::send(const NDHelper &dt)
{
    // send data to each connected client
    foreach( QTcpSocket *client, m_clientList )
    {
        client->write((char*)&dt, sizeof(dt));
    }

}
