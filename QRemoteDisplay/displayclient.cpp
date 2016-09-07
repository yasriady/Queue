#include "displayclient.h"

DisplayClient::DisplayClient(QObject *parent) : QObject(parent)
{
    m_connected = false;
    m_tcpSocket = new Socket(this);
    connect( m_tcpSocket, SIGNAL( readyRead()), this, SLOT(slotReadyRead()) );
    connect( m_tcpSocket, SIGNAL( disconnected()), this, SLOT(slotSocketDisconnected()) );
    connect( m_tcpSocket, SIGNAL( error(QAbstractSocket::SocketError) ), this, SLOT(slotSocketError(QAbstractSocket::SocketError)) );
    connect( m_tcpSocket, SIGNAL( connected() ), this, SLOT( slotConnected() ) );

    m_callerSound = new CallerSound(this);
}

DisplayClient::~DisplayClient()
{
    delete m_callerSound;
    delete m_tcpSocket;
}

bool DisplayClient::isConnected()
{
    m_connected = ( m_tcpSocket->state() == QTcpSocket::ConnectedState );
    return m_connected;
}

void DisplayClient::slotReadyRead()
{
    NodeData dt;
    m_tcpSocket->read( (char*)&dt, sizeof(dt) );
    m_dt.setDt(dt);

    m_node = parent()->findChild<Node*>( m_dt.nodeName() );
    if( !m_node ) {
        //LOGGER("Node object is not exist");
        return;
    }

    m_node->updateUi(m_dt);
    m_bigNode->updateUi(&m_dt);
    m_callerSound->makeSound(m_dt);

}

void DisplayClient::slotSocketError(QAbstractSocket::SocketError)
{

}

void DisplayClient::slotSocketDisconnected()
{
    m_connected = false;
    m_statusBarWidget->setLabel1(DISCONNECTED);
}

void DisplayClient::slotConnected()
{
    m_connected = true;
    m_statusBarWidget->setLabel1(CONNECTED);
}

void DisplayClient::setStatusBarWidget(StatusBarWidget *statusBarWidget)
{
    m_statusBarWidget = statusBarWidget;
}

void DisplayClient::connectToHost()
{
    if( isConnected() ) return;
    mkCONFIG;
    m_tcpSocket->connectToHost(DISPLAYSERVER, REMOTEDISPLAYPORT);
    if( m_tcpSocket->waitForConnected(1000))
        m_connected = true;
}

void DisplayClient::disconnectFromHost()
{
    m_tcpSocket->close();
}
