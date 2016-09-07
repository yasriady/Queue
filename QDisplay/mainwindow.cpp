#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mainwindowbase.h"

MainWindow::MainWindow(QWidget *parent) :
    MainWindowBase(parent)
{
    m_displayServer = new DisplayServer(m_db, ui->bigNode, this);

    m_statusBarWidget = new StatusBarWidget(ui->statusBar);
    ui->statusBar->addPermanentWidget( m_statusBarWidget, 1 );
    m_displayServer->setStatusBarWidget(m_statusBarWidget);

    ui->pushButton_CONNECT->hide();
    //ui->pushButton_DISCONNECT->hide();
    //ui->pushButton_WRITEBACK->hide();

}

MainWindow::~MainWindow()
{
    delete m_displayServer;
}

void MainWindow::on_pushButton_CONNECT_clicked()
{

}

void MainWindow::on_pushButton_DISCONNECT_clicked()
{

}

void MainWindow::on_pushButton_WRITEBACK_clicked()
{
    m_displayServer->test();
}

void MainWindow::customInit()
{
    m_windowName = "MainWindow";
    setWindowTitle("QDisplay");

    ui->runningText->setDb(m_db);

}
