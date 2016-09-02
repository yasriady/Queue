#include "mainwindowchild.h"

MainWindowChild::MainWindowChild(QWidget *parent)
    : MainWindow(parent)
{
    setWindowTitle("MainWindow (QRemoteDisplay)");
    m_tcpSocket = new QTcpSocket(this);
    mkCONFIG;
    m_tcpSocket->connectToHost(DISPLAYSERVER, REMOTEDISPLAYPORT, QIODevice::ReadWrite);
}

MainWindowChild::~MainWindowChild()
{

}

