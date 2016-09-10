#include "mainwindow.h"
#include "ui_mainwindowbase.h"


MainWindow::MainWindow(QWidget *parent) :
    MainWindowBase(parent)
{
    customInit(this, "MainWindow", "QRemoteDisplay", true);

    m_displayClient = new DisplayClient(this);
    m_displayClient->setBigNode(ui->bigNode);

    m_statusBarWidget = new StatusBarWidget(ui->statusBar);
    ui->statusBar->addPermanentWidget( m_statusBarWidget, 1 );
    m_statusBarWidget->setLabel1( DISCONNECTED );
    m_displayClient->setStatusBarWidget(m_statusBarWidget);

    //ui->pushButton_CONNECT->hide();
    ui->pushButton_WRITEBACK->hide();

    updateUi();

}

MainWindow::~MainWindow()
{
    delete m_displayClient;
}

void MainWindow::updateUi()
{
    m_statusBarWidget->setLabel7( QString("SVR:%1").arg(m_config->string("DisplayServer")));
}

//void MainWindow::customInit()
//{
//    m_windowName = "MainWindow";
//    setWindowTitle("QRemoteDisplay");

//    ui->runningText->setDb(m_db);

//}

void MainWindow::on_pushButton_CONNECT_clicked()
{
    m_displayClient->connectToHost();
}

void MainWindow::on_pushButton_DISCONNECT_clicked()
{
    m_displayClient->disconnectFromHost();
}

void MainWindow::on_pushButton_WRITEBACK_clicked()
{

}
