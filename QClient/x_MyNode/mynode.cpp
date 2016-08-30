#include "mynode.h"
#include "ui_mynode.h"

MyNode::MyNode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyNode)
{
    ui->setupUi(this);

    m_hostName = "192.168.1.2";
    m_port = 7001;
    m_tcpSocket = new MySocket(m_hostName, m_port);

    QTimer *timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(slotMyTimer()) );
    timer->start(10);

    QString string = "__PRETTY_FUNCTION__";
    qDebug() << string;


}

MyNode::~MyNode()
{
    delete m_tcpSocket;
    delete ui;
}

void MyNode::on_toolButton_Login_clicked()
{
    Login();
}

void MyNode::on_toolButton_Calling_clicked()
{
    Call();
}

void MyNode::on_toolButton_Serving_clicked()
{
    Serving();
}

void MyNode::on_toolButton_Ping_clicked()
{
    Ping();
}

bool MyNode::connectToHost()
{
    qDebug() << m_macAddress;
    strcpy(m_nodeData.macAddress, m_macAddress.toLatin1() );

    if( m_tcpSocket->isConnected() )
        m_tcpSocket->disconnectFromHost();
    bool connected = m_tcpSocket->connectToHost();
    return connected;
}

QString MyNode::getMacAddress2()
{
    foreach( QNetworkInterface interface, QNetworkInterface::allInterfaces() )
    {
        // Return only first non loopback MAC Address
        if( !(interface.flags() & QNetworkInterface::IsLoopBack ) )
            return interface.hardwareAddress();
        QString text = interface.hardwareAddress();
        //qDebug() << text;
    }
    return "";
}

void MyNode::setMacAddress(const QString &macAddress)
{
    m_macAddress = macAddress;
}

void MyNode::slotReadyRead()
{

    m_tcpSocket->read( (char*)&m_nodeData, sizeof(NodeData) );

    QString displayName;
    //displayName = QString::fromLatin1(m_nodeData.displayedName);
    //ui->label_DisplayName->setText(displayName);

    switch ( m_nodeData.action ) {

    case LOGIN:

        displayName = QString::fromLatin1(m_nodeData.displayedName);
        ui->displayedName->setText(displayName);

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

void MyNode::slotMyTimer()
{
    // contoh: QSoundEffect *s = qobject_cast<QSoundEffect*>(sender());
    QTimer *timer =  qobject_cast<QTimer*> (sender());
    timer->deleteLater();
    // run autologin only if this QWidget as clientMode (see it's dynamic property)
    Login();
}

void MyNode::Login()
{
    if( !connectToHost() ) return;
    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );

    // Customize
    m_nodeData.action = LOGIN;
    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));

    //m_tcpSocket->disconnectFromHost();

}

void MyNode::Call()
{
    if( !connectToHost() ) return;
    connect( m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()) );

    // Customize
    m_nodeData.action = CALL;

    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));
    //m_tcpSocket->disconnectFromHost();

}

void MyNode::Serving()
{
    if( !connectToHost() ) return;

    // Customize
    m_nodeData.action = SERVING;

    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));
    m_tcpSocket->disconnectFromHost();
}

void MyNode::Ping()
{
    if( !connectToHost() ) return;

    // Customize
    m_nodeData.action = PING;

    m_tcpSocket->write( (char*)&m_nodeData, sizeof(NodeData));
    m_tcpSocket->disconnectFromHost();
}

void MyNode::showDisplayedName(const QString &text)
{
    ui->displayedName->setText(text);
}

void MyNode::showNodeame(const QString &text)
{
    ui->nodeName->setText(text);
}

void MyNode::showMacAddress()
{
    ui->macAddress->setText(m_macAddress);
}

void MyNode::showEvent(QShowEvent *event)
{
    m_clientMode = property("clientMode").toBool();
    m_macAddress = m_clientMode ? getMacAddress2() : property("macAddress").toString();
    ui->macAddress->setText(m_macAddress);
}

void MyNode::on_pushButton_clicked()
{

}
