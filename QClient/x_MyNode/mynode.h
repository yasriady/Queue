#ifndef MYNODE_H
#define MYNODE_H

#include <QWidget>
#include <QTcpSocket>
#include "mysocket.h"
#include <QNetworkInterface>
#include <QtDebug>
#include <QTimer>

namespace Ui {
class MyNode;
}

class MyNode : public QWidget
{
    Q_OBJECT

public:
    explicit MyNode(QWidget *parent = 0);
    ~MyNode();

private slots:
    void on_toolButton_Calling_clicked();

    void on_toolButton_Login_clicked();

    void on_toolButton_Serving_clicked();

    void on_toolButton_Ping_clicked();

private:
    Ui::MyNode *ui;

private:
    QString m_hostName;
    quint16 m_port;
    //NodeData m_nodeData;
    NodeData m_nodeData;
    QString m_macAddress;
    MySocket *m_tcpSocket;
    bool connectToHost();

public:
    QString getMacAddress2();

public:
    void setMacAddress(const QString &macAddress);
    const QString getMacAddress() { return m_macAddress; }

private slots:
    void slotReadyRead();
    void slotMyTimer();

    void on_pushButton_clicked();

private:
    void Login();
    void Call();
    void Serving();
    void Ping();

public:
    void showStatus();
    void showTicketNo();
    void showDisplayedName(const QString &text);
    void showNodeame(const QString &text);
    void showMacAddress();


protected:
    virtual void showEvent(QShowEvent *event);

private:
    bool m_clientMode;

};

#endif // MYNODE_H
