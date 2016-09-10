#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    customInit(this, "MainWindow", "MainWindow", true);
    //m_db = new DB(); m_dB = m_db;
    m_displayServer = new DisplayServer(this);

    connect( m_displayServer, SIGNAL(signalDataReady(NDHelper)), this, SLOT(slotDataReady(NDHelper)) );
    connect( m_displayServer->remoteDisplay() , SIGNAL(signalConnectionInfo(QString)), this, SLOT(slotConnectionInfo(QString)) );
    connect( m_displayServer, SIGNAL(signalLog(QString)), this, SLOT(slotLog(QString)) );

    m_statusBarWidget = new StatusBarWidget(ui->statusBar);
    ui->statusBar->addPermanentWidget( m_statusBarWidget, 1 );
    m_statusBarWidget->setLabel1( "Remote: 0" );

}

MainWindow::~MainWindow()
{
    // global variable destructed here!
    delete m_dB;
    if( m_config != NULL ) delete m_config;
    if( m_confix != NULL ) delete m_confix;

    delete m_statusBarWidget;
    delete m_displayServer;
    delete ui;
}

void MainWindow::addNewTab()
{
    // check, who sent the command?
    QCommandLinkButton *cmd = qobject_cast<QCommandLinkButton*>(sender());

    if( pageExist( cmd->objectName().replace("cmd", "Form") ) )
        return;

    QWidget *widget;

    if( cmd == ui->cmdNodeList )
    {
        widget = new FormNodeList(ui->tabWidget);
    }

    else if( cmd == ui->cmdGroupList )
    {
        widget = new FormGroupList(ui->tabWidget);
    }

    else if( cmd == ui->cmdReport )
    {
        widget = new FormReport(ui->tabWidget);
    }

    else return;

    //const QString &formName = widget->objectName();
    const QString &formText = widget->windowTitle();
    ui->tabWidget->addTab(widget, formText);
    ui->tabWidget->setCurrentWidget(widget);

}

bool MainWindow::pageExist(const QString &formName)
{
    //bool result = false;
    for( int i=0; i<ui->tabWidget->count(); i++ )
    {
        QWidget* w = ui->tabWidget->widget(i);
        const QString &name = w->objectName();
        //__PF(name);
        //__PF(formName);
        if( name == formName ) {
            ui->tabWidget->setCurrentIndex(i);
            return true;
        }
    }
    return false;
}

//DB *MainWindow::db() const
//{
//    return m_db;
//}

void MainWindow::slotDataReady(NDHelper dt)
{

}

void MainWindow::slotConnectionInfo(QString string)
{
    m_statusBarWidget->setLabel1(string);
}

void MainWindow::slotLog(QString string)
{
    ui->logger->log(string);
}

void MainWindow::on_actionLogger_triggered()
{
    ui->logger->toggleVisibility();
}

void MainWindow::on_cmdNodeList_clicked()
{
    addNewTab();
}

void MainWindow::on_cmdGroupList_clicked()
{
    addNewTab();
}

void MainWindow::on_cmdWelcome_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_cmdReport_clicked()
{
    addNewTab();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if( index==0 ) return;
    ui->tabWidget->removeTab(index);
}
