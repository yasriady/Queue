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
//    if( m_busy )
//    {
//        __PF("Busy men ..!");
//        //m_tcpServer->nextPendingConnection()->close();
//        NDHelper dt;
//        dt.setServerAnswer(SRVANSWER::SRVBUSY);
//        m_msg = m_db->getTaxonomy(ERR_SRVBUSY, 0);
//        dt.setMessage(m_msg);
//        NodeData d = dt.dt();
//        Socket *tcpSocket = (Socket*) m_tcpServer->nextPendingConnection();
//        tcpSocket->write( (char*)&d, sizeof(d) );
//        tcpSocket->close();
//        return;
//    }
    m_connected = true;
    m_tcpSocket = (Socket*) m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(slotSocketDisconnected()) );
    connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotSocketError(QAbstractSocket::SocketError)) );
    m_availableRemoteDisplay.append(this);
}

void RemoteDisplay::slotReadReady()
{

}

void RemoteDisplay::slotSocketError(QAbstractSocket::SocketError)
{
    m_connected = false;
}

void RemoteDisplay::slotSocketDisconnected()
{
    m_connected = false;
}
