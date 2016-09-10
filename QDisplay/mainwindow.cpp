#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mainwindowbase.h"

MainWindow::MainWindow(QWidget *parent) :
    MainWindowBase(parent)
{
    customInit(this, "MainWindow", "QDisplay", true);

    m_displayServer = new DisplayServer(this);
    connect( m_displayServer, SIGNAL(signalDataReady(NDHelper)), this, SLOT(slotDataReady(NDHelper)) );
    connect( m_displayServer->remoteDisplay() , SIGNAL(signalConnectionInfo(QString)), this, SLOT(slotConnectionInfo(QString)) );

    m_statusBarWidget = new StatusBarWidget(ui->statusBar);
    ui->statusBar->addPermanentWidget( m_statusBarWidget, 1 );
    m_statusBarWidget->setLabel1( "Remote: 0" );

    ui->pushButton_CONNECT->hide();
    //ui->pushButton_DISCONNECT->hide();
    //ui->pushButton_WRITEBACK->hide();

    updateUi();
}

MainWindow::~MainWindow()
{
    //delete m_remoteDisplay;
    delete m_displayServer;
}

void MainWindow::updateUi()
{
    m_statusBarWidget->setLabel7( QString("%1:%2").arg(m_config->string("DBManager/driver")).arg(m_config->string("DBManager/server")) );
}

void MainWindow::on_pushButton_CONNECT_clicked()
{

}

void MainWindow::on_pushButton_DISCONNECT_clicked()
{

}

void MainWindow::on_pushButton_WRITEBACK_clicked()
{

}

void MainWindow::slotDataReady(NDHelper dt)
{
    Node* node = findChild<Node*>(dt.nodeName());
    if( !node ) {
        //LOGGER("Node object is not exist");
        return;
    }
    node->updateUi(dt);
    ui->bigNode->updateUi(&dt);
    //m_remoteDisplay->send(dt);
}

void MainWindow::slotConnectionInfo(QString string)
{
    m_statusBarWidget->setLabel1(string);
}

//void MainWindow::customInit()
//{
//    m_windowName = "MainWindow";
//    setWindowTitle("QDisplay");

//    ui->runningText->setDb(m_db);

//}
