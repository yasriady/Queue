#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QTcpSocket>
#include "mysocket.h"
#include <QNetworkInterface>
#include <QTimer>
#include <QMainWindow>
#include <def.h>

namespace Ui {
class Node;
}

class Node : public QFrame
{
    Q_OBJECT

public:
    explicit Node(QWidget *parent = 0);
    ~Node();

private slots:
    void on_toolButton_Login_clicked();
    void on_toolButton_Logout_clicked();
    void on_toolButton_Calling_clicked();
    void on_toolButton_Serving_clicked();
    void on_toolButton_Ping_clicked();

private:
    Ui::Node *ui;

private:
    QString m_hostName;
    quint16 m_port;
    //NodeData m_nodeData;
    NodeData m_nodeData;
    QString m_macAddress;
    MySocket *m_tcpSocket;
    bool connectToHost();
    bool disconnectFromHost();

public:
    QString getMacAddress();

public:
    void setMacAddress(const QString &macAddress);

private slots:
    void slotReadyRead();
    void slotMyTimer();

    void on_pushButton_clicked();


private:
    void Login();
    void Logout();
    void Calling();
    void Serving();
    void Ping();

public:
    void showStatus();
    void showTicketNo();
    void showDisplayedName(const QString &text);
    void showNodeName(const QString &text);
    void showMacAddress();
    void setButton(const bool &login);

    bool getConnected() const;
    QString getMessage() const;
    QString getGroupCode() const;
    QString getNodeName() const;

protected:
    virtual void showEvent(QShowEvent *event);

private:
    bool m_simulationMode;
    bool m_connected;
    QString m_message;

    QString m_displayedName;
    QString m_nodeName;
    QString m_queueNo;
    QString m_GroupCode;
    QString m_status;

signals:
    void signalResult(const Node *node);

};

#endif // NODE_H
