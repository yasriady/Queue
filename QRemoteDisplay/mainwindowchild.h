#ifndef MAINWINDOWCHILD_H
#define MAINWINDOWCHILD_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTcpSocket"
#include "../SharedClass/config.h"
#include <dsettings.h>

class MainWindowChild : public MainWindow
{
    Q_OBJECT

public:
    explicit MainWindowChild(QWidget *parent = 0);
    ~MainWindowChild();

private:
    QTcpSocket *m_tcpSocket;

};

#endif // MAINWINDOWCHILD_H
