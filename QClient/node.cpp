#include "node.h"
#include "ui_node.h"

Node::Node(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Node)
{
    ui->setupUi(this);

    m_hostName = "192.168.1.2";
    m_port = 7001;
    m_tcpSocket = new MySocket(m_hostName, m_port);

    QTimer *timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(slotMyTimer()) );
    timer->start(1);

}

Node::~Node()
{
    delete m_tcpSocket;
    delete ui;
}

void Node::on_toolButton_Login_clicked()
{ Login(); }

void Node::on_toolButton_Logout_clicked()
{ Logout(); }

void Node::on_toolButton_Calling_clicked()
{ Calling(); }

void Node::on_toolButton_Serving_clicked()
{ Serving(); }

void Node::on_toolButton_Ping_clicked()
{ Ping(); }

bool Node::connectToHost()
{
    bool connected;
    strcpy(m_nodeData.macAddress, m_macAddress.toUtf8() );
    if( m_tcpSocket->isConnected() )
        m_tcpSocket->disconnectFromHost();
    connected = m_tcpSocket->connectToHost();
    return connected;
}

bool Node::disconnectFromHost()
{
    m_tcpSocket->disconnectFromHost();
    return ! m_tcpSocket->isConnected();
}

QString Node::getMacAddress()
{
    return m_macAddress;
}

void Node::setMacAddress(const QString &macAddress)
{
    m_macAddress = macAddress;
}

void Node::slotReadyRead()
{

    m_tcpSocket->read( (char*)&m_nodeData, sizeof(NodeData) );

    switch ( m_nodeData.action ) {
    case LOGIN:

        m_displayedName = QString::fromUtf8( m_nodeData.displayedName);
        m_nodeName      = QString::fromUtf8( m_nodeData.nodeName );
        m_queueNo       = QString::fromUtf8( m_nodeData.queueNo);
        m_GroupCode     = QString::fromUtf8( m_nodeData.groupCode);
        m_status        = QString::fromUtf8( m_nodeData.status);

        ui->displayedName-> setText(m_displayedName);
        ui->nodeName->      setText(m_nodeName);
        ui->queueNo->       setText(m_queueNo);
        ui->groupCode->     setText(m_GroupCode);
        ui->status->        setText(m_status);

        emit signalResult(this);

        break;

    case ACTION::CALL:

        //LOGGER("CALL by " + clientConnection->peerAddress().toString() );
        break;

    case SERVING:

        //LOGGER("SERVING by " + clientConnection->peerAddress().toString() );
        break;

    case PING:

        //LOGGER("PING from " + clientConnection->peerAddress().toString() );
        break;

    default:

        //LOGGER("NONE from " + clientConnection->peerAddress().toString() );
        break;

    }

}

void Node::slotMyTimer()
{
    // contoh: QSoundEffect *s = qobject_cast<QSoundEffect*>(sender());
    QTimer *timer =  qobject_cast<QTimer*> (sender());
    timer->deleteLater();
    // run autologin only if this QWidget as clientMode (see it's dynamic property)
    //Login();
}

void Node::Login()
{
    m_connected = connectToHost();
    if( !m_connected ) {
        m_message = NOTCONNECTED;
        emit signalResult(this);
        return;
    }
    m_message = CONNECTED;
    emit signalResult(this);

    setButton(m_connected);
    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );

    // Customize these:
    m_nodeData.action = LOGIN;
    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));

    //m_tcpSocket->disconnectFromHost();

}

void Node::Logout()
{
    m_connected = ! disconnectFromHost();
    m_message = LOGOUT;
    emit signalResult(this);
    setButton(m_connected);

    ui->status->setText("");
    ui->queueNo->setText("");
    ui->displayedName->setText("");
    m_status = "";
    m_queueNo = "";
    m_displayedName = "";
    m_nodeName = "";
    m_GroupCode = "";
    emit signalResult(this);
}

void Node::Calling()
{
    m_connected = connectToHost();
    m_message = CONNECTED;
    if( !m_connected ) {
        m_message = NOTCONNECTED;
        emit signalResult(this);
    }
    //emit signalResult(this); // pindah ke slotReadyRead(), case LOGIN

    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );

    // Customize these:
    m_nodeData.action = CALL;
    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));

    //m_tcpSocket->disconnectFromHost();
}

void Node::Serving()
{
    if( !connectToHost() ) return;

    // Customize
    m_nodeData.action = SERVING;

    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));
    m_tcpSocket->disconnectFromHost();
}

void Node::Ping()
{
    if( !connectToHost() ) return;

    // Customize
    m_nodeData.action = PING;

    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));
    m_tcpSocket->disconnectFromHost();
}

void Node::showDisplayedName(const QString &text)
{
    ui->displayedName->setText(text);
}

void Node::showNodeName(const QString &text)
{
    ui->nodeName->setText(text);
}

void Node::showMacAddress()
{
    ui->macAddress->setText(m_macAddress);
}

void Node::setButton(const bool &login)
{
    ui->toolButton_Login->setEnabled(!login);
    ui->toolButton_Logout->setEnabled(login);
    ui->toolButton_Calling->setEnabled(login);
    ui->toolButton_Serving->setEnabled(login);
    ui->toolButton_Ping->setEnabled(login);

}


void Node::showEvent(QShowEvent */*event*/)
{
    m_simulationMode = property("simulationMode").toBool();
    if( m_simulationMode ) {
        m_macAddress = property("macAddress").toString();
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
    //ui->macAddress->setText(m_macAddress);

    ui->macAddress->hide();
    ui->nodeName->hide();
    ui->groupCode->hide();

}

QString Node::getNodeName() const
{
    return m_nodeName;
}

QString Node::getGroupCode() const
{
    return m_GroupCode;
}

QString Node::getMessage() const
{
    return m_message;
}

bool Node::getConnected() const
{
    return m_connected;
}

void Node::on_pushButton_clicked()
{

}

