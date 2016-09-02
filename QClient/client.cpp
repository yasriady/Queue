#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent, QLineEdit *mac) :
    DMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    init();

    m_dt = new NDHelper();
    m_rd = new RDHelper();

    m_windowName = property("windowName").toString();
    mkCONFIG; mkCONFIX;
    m_hostName = confg->string( KEY("displayServer"), "192.168.1.2" );
    m_port = confg->integr( KEY("displayServerPort"), 9000 );
    m_tcpSocket = new MySocket(m_hostName, m_port);
    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );

    //QTimer *timer = new QTimer(this);
    //connect( timer, SIGNAL(timeout()), this, SLOT(slotMyTimer()) );
    //timer->start( mkRandom(99, 562) );  // random timerize

    m_simulationMode = confx->boolean(KEY("simulationMode"), true) ; //property("simulationMode").toBool();

    // set macAddress
    if( m_simulationMode ) {
        m_macAddress = confx->string(KEY("macAddress"), "8C:89:A5:57:A6:41"); //property("macAddress").toString();
    } else {
        foreach( QNetworkInterface interface, QNetworkInterface::allInterfaces() )
        {
            // Return only first non loopback MAC Address
            if( !(interface.flags() & QNetworkInterface::IsLoopBack ) ) {
                m_macAddress = interface.hardwareAddress();
                break;
            }
            m_macAddress = interface.hardwareAddress();
        }
    }

    if( parent ) {
        // if simulation mode
        m_simulationMode = true;
        m_macAddress = mac->text();
        m_windowName = "Window_" + m_macAddress;
        ui->menubar->hide();
        ui->statusBar->hide();
    }

    // ... no longer used, so make them hidden
    //ui->toolButton_Login->hide();
    //ui->toolButton_Logout->hide();

    ui->menubar->hide();
    ui->statusBar->hide();

    ui->init->hide();

    m_rd->setMacAddress(m_macAddress);
    SB->setMacAddress(m_macAddress);

    on_init_clicked();
}

Client::~Client()
{
    delete m_dt;
    delete m_rd;
    delete m_tcpSocket;
    delete ui;
}

bool Client::connectToHost()
{
    bool connected;
    if( m_tcpSocket->isConnected() )
        m_tcpSocket->disconnectFromHost();
    connected = m_tcpSocket->connectToHost();
    return connected;
}

bool Client::disconnectFromHost()
{
    m_tcpSocket->disconnectFromHost();
    return ! m_tcpSocket->isConnected();

}

void Client::updateUi()
{
    QString dateTime = ( m_dt->request()== REQUEST::CALLING ) ? m_dt->callingTimeText() : m_dt->processTimeText();
    dateTime = dateTime.replace("T", " ", Qt::CaseInsensitive);
    dateTime =(QDateTime::fromString(dateTime, DATETIMEFORMAT)).toString(TIMEFORMAT);

    QString calledCountText = "";
    if( m_dt->request()==REQUEST::CALLING )
        calledCountText = QString( "%1x" ).arg(m_dt->calledCount());

    ui->queueNo->setText        ( m_dt->queueNoText()       );
    ui->status->setText         ( m_dt->requestText()       );
    ui->service->setText        ( m_dt->service()           );
    ui->dateTime->setText       ( dateTime                  );
    ui->displayedName->setText  ( m_dt->displayedName()     );
    ui->calledCount->setText    ( calledCountText           );

    // label
//    QString status = tr(m_dt.clientRequest_s); status = (status == CALLING_) ? status + QString(" : %1x").arg(m_dt.calledCount) : status;
//    const QString &groupCode = tr( m_dt.groupCode );
//    const int &queueNo = (int)m_dt.queueNo;

//    QString dateTime_;
//    if( m_dt.clientRequest == CLIREQUEST::CLI_CALLING )
//    {
//        dateTime_ = (tr(m_dt.callingTime_s)).right(8);

//    }
//    if( m_dt.clientRequest == CLIREQUEST::CLI_PROCESS )
//    {
//        dateTime_ = (tr(m_dt.processTime_s)).right(8);
//    }

//    ui->status->setText( status );
//    //ui->queueNo->setText( QString::number(m_dt.queueNo) );
//    ui->queueNo->setText( TICKET(groupCode, queueNo) );
//    ui->displayedName->setText( tr(m_dt.displayedName) );

//    // statusbar
//    SB->setConnected( m_dt.connected );
//    SB->setMessage( m_dt.message );
//    SB->setGroupCode( m_dt.groupCode );
//    SB->setNodeName( m_dt.nodeName );
//    SB->setMacAddress( m_dt.macAddress );
//    SB->setCalledCount( m_dt.calledCount);

//    // internal
//    ui->m_action->setText( str(m_dt.clientRequest)  );
//    ui->m_macAddress->setText( m_dt.macAddress );
//    ui->m_nodeId->setText( str(m_dt.nodeId) );
//    ui->m_ipAddressClient->setText( m_dt.ipAddressClient );
//    ui->service->setText( m_dt.service );
//    ui->dateTime->setText( dateTime_ );

}

void Client::make(const REQUEST &request)
{
    // clear/or set ui
    ui->message->setText("msg");

    // send request
    m_rd->setRequest(request);
    RequestData *rd = m_rd->rd();
    m_tcpSocket->write( (char*)rd, sizeof(*rd) );
}

void Client::slotReadyRead()
{
    NodeData dt;// = m_dt->dt();
    m_tcpSocket->read( (char*)&dt, sizeof(dt) );

    m_dt->setDt(dt);

    switch (m_dt->serverAnswer()) {

    case SRVBUSY:
        ui->message->setText( m_dt->message() );
        return;
        break;

    default:
        break;

    }


    switch ( m_dt->request() ) {

    case REQUEST::INIT:
        //LOGGER("INIT from " + clientConnection->peerAddress().toString() );
        break;

    case REQUEST::LOGIN:
        //LOGGER("LOGIN from " + clientConnection->peerAddress().toString() );
        break;

    case REQUEST::CALLING:
        //__PF( m_tcpSocket->peerName() );
        //LOGGER("CALL by " + m_tcpSocket->peerAddress().toString() );
        break;

    case REQUEST::PROCESS:
        //LOGGER("SERVING by " + m_tcpSocket->peerAddress().toString() );
        //break;

    case REQUEST::PING:
        //LOGGER("PING from " + clientConnection->peerAddress().toString() );
        break;

    default:
        //LOGGER("NONE from " + clientConnection->peerAddress().toString() );
        break;
    }

    updateUi();

}

void Client::slotMyTimer()
{
    QTimer *timer =  qobject_cast<QTimer*> (sender());
    timer->deleteLater();
    // to run auto login
    //on_toolButton_Login_clicked();

}


void Client::on_actionExit_triggered()
{
    QApplication::quit();
}

void Client::on_actionLogin_triggered()
{

}

void Client::on_actionLogout_triggered()
{
}

QWidget *Client::getWidget()
{
    return ui->centralWidget;
}

void Client::doLogin()
{
}

void Client::on_calling_clicked()
{
    if( connectToHost() ) make( REQUEST::CALLING);
}

void Client::on_process_clicked()
{
    if( connectToHost() ) make( REQUEST::PROCESS);
}

void Client::on_init_clicked()
{
    if( connectToHost() ) make( REQUEST::INIT);
}

void Client::on_pushButton_clicked()
{
}

