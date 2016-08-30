#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    connect( ui->NODE, SIGNAL( signalResult(const Node*) ), this, SLOT(slotResult(const Node*)) );

    SB->setMacAddress( ui->NODE->getMacAddress()  );

}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::slotResult(const Node *node)
{
    SB->setConnected(node->getConnected() );
    SB->setMessage( node->getMessage() );
    SB->setNodeName( node->getNodeName());
    SB->setGroupCode(node->getGroupCode() );
}

void ClientWindow::on_pushButton_Test_clicked()
{
    ui->statusbar->setConnected(true);
    ui->statusbar->setMessage(CONNECTED);
}

void ClientWindow::on_pushButton_Test2_clicked()
{
    ui->statusbar->setConnected(false);
    ui->statusbar->setMessage(NOTCONNECTED);
}

void ClientWindow::on_pushButton_clicked()
{
}

void ClientWindow::showEvent(QShowEvent *event)
{
    SB->setMacAddress( ui->NODE->getMacAddress() );
    DMainWindow::showEvent(event);
}
