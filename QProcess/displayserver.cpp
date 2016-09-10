#include "displayserver.h"

DisplayServer::DisplayServer(QObject *parent) : QObject(parent)
{
    //m_db = db;
    //m_db = m_dB;

//    m_init = true;
//    m_busy = false;
//    m_msg = "";
    m_dt.setInit(true);
    m_dt.setBusy(false);
    m_dt.setMessage("");

    m_callerSound = new CallerSound(this);
    connect( m_callerSound, SIGNAL(signalSoundFinish()), this, SLOT(slotSoundFinish()) );
    //m_bigNode = bigNode;

    m_tcpServer = new QTcpServer(this);
    if( !m_tcpServer->listen(QHostAddress::AnyIPv4, SERVER_PORT) )
    {
        //slotLogger("server listen error!");
        return;
    } else {
        //slotLogger("server listen OK!");
    }
    connect( m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()) );

    m_remoteDisplay = new RemoteDisplay(this);

}

DisplayServer::~DisplayServer()
{
    delete m_remoteDisplay;
    delete m_tcpServer;
}

//void DisplayServer::setStatusBarWidget(StatusBarWidget *statusBarWidget)
//{
//    m_statusBarWidget = statusBarWidget;
//    //m_remoteDisplay->setStatusBarWidget(m_statusBarWidget);
//}

void DisplayServer::slotNewConnection()
{
    //__PF__;
    if( m_dt.busy() )
    {
        // just create new socket !
        //__PF("Busy men ..!");
        //m_tcpServer->nextPendingConnection()->close();
        NDHelper dt;
        dt.setServerAnswer(SRVANSWER::SRVBUSY);
        const QString &msg = m_dB->getTaxonomy(ERR_SRVBUSY, 0);
        dt.setMessage(msg);
        NodeData d = dt.dt();
        QTcpSocket *tcpSocket = m_tcpServer->nextPendingConnection();

        // insert ip address
        const QHostAddress &peerAddress = m_tcpSocket->peerAddress();
        dt.setIpAddressClient( peerAddress.toString() );
        emit signalLog( QString("BUSY: New connection from %1").arg(peerAddress.toString()) );

        tcpSocket->write( (char*)&d, sizeof(d) );
        tcpSocket->close();
        return;
    }

    m_tcpSocket = m_tcpServer->nextPendingConnection();
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );
}

void DisplayServer::slotReadyRead()
{
    RequestData *rd = m_rd.rd();
    NodeData d;

    m_tcpSocket->read( (char*)rd, sizeof(*rd) );
    QString macAddress = m_rd.macAddress();
    QString nodeName = m_dB->getNodeName(macAddress);

    if( nodeName == NOTFOUND ) {
        //LOGGER( "Node with mac address "+ macAddress +" not registered" );
        m_dt.setServerAnswer(SRVANSWER::NOTREGISTERED);
        const QString &msg = m_dB->getTaxonomy( ERR_NOTREGISTERED, 0 );
        m_dt.setMessage(msg);
        d = m_dt.dt();
        m_tcpSocket->write( (char*)&d, sizeof(d) );
        m_tcpSocket->close();
        return;
    }

//    m_node = parent()->findChild<Node*>(nodeName);
//    if( !m_node ) {
//        //LOGGER("Node object is not exist");
//        return;
//    }

    // OK, client is valid ...

    //m_dt = m_node->dt();        // refresh data
    m_dt = m_dB->getNodeInfoByName2(nodeName);

    m_dt.setBusy(true);
    bool init = ( m_rd.request()==REQUEST::INIT ) ? true : false;
    m_dt.setInit(init);

    MyMap rcd2;

    REQUEST request = m_rd.request();
    m_dt.setRequest( request );

    switch ( request ) {

    case REQUEST::INIT:
        rcd2 = m_dB->getLastQueue( nodeName );
        if( rcd2["status"].toString().toInt()==1 ) request = REQUEST::CALLING;
        if( rcd2["status"].toString().toInt()==2 ) request = REQUEST::PROCESS;
        m_dt.setQueueNo( (uint16_t) rcd2["queue_no"].toString().toInt() );
        break;

    case REQUEST::LOGIN :
        //emit signalLog( "Client LOGIN from " + QString(m_dt.macAddress) );
        //rcd = m_db->doLogin( m_dt.nodeName );
        break;

    case REQUEST::CALLING :
        //emit signalLog( "Client CALL from " + QString(m_dt.macAddress) );
        rcd2 = m_dB->doCalling( nodeName );
        m_dt.setGroupCode( rcd2["group_code"].toString() );
        m_dt.setQueueNo( rcd2["queue_no"].toInt() );
        m_dt.setCallingTimeText( rcd2["calling_time"].toString() );
        m_dt.setCalledCount( rcd2["called_count"].toString().toInt()  );
        break;

    case REQUEST::PROCESS :
        //emit signalLog( "Client do PROCESS : " + QString(m_dt.macAddress) );
        rcd2 = m_dB->doProcess( nodeName );
        m_dt.setQueueNo( rcd2["queue_no"].toInt() );
        m_dt.setProcessTimeText( rcd2["process_time"].toString() );
        m_dt.setNumOfWaiting( m_dB->getNumOfWaiting( m_dt.groupCode() ) );
        break;

    case REQUEST::PING :
        //emit signalLog( "Client PING from " + QString(m_dt.macAddress) );
        //rcd = m_db->doPing( m_dt.nodeName );
        break;
    default:
        break;
    }

    // request might already altered, thus need to updated
    m_dt.setRequest(request);
    m_dt.setServerAnswer(SRVANSWER::REQUESTOK);
    m_dt.setRequestText( REQUESTTEXT(request) );

    // insert ip address
    const QHostAddress &peerAddress = m_tcpSocket->peerAddress();
    m_dt.setIpAddressClient( peerAddress.toString() );
    //emit signalLog( QString("New connection from %1").arg(peerAddress.toString()) );

    // send data back to client
    d = m_dt.dt();
    m_tcpSocket->write( (char*)&d, sizeof(d) );

    emit signalDataReady(m_dt);
    //m_node->updateUi(m_dt);
    //m_bigNode->updateUi(&m_dt);
    m_callerSound->makeSound(m_dt);
    m_remoteDisplay->send(m_dt);
    emit signalLog( QString("%1 from %2 / %3").arg( m_dt.requestText() ).arg( m_dt.displayedName() ).arg( m_dt.ipAddressClient() ) );

}

void DisplayServer::slotSoundFinish()
{
    m_dt.setBusy(false);
}

RemoteDisplay *DisplayServer::remoteDisplay() const
{
    return m_remoteDisplay;
}
