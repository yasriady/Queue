#ifndef DISPLAYSERVER_H
#define DISPLAYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "../SharedClass/config.h"
#include "../SharedClass/ndhelper.h"
#include "../SharedClass/rdhelper.h"
#include "../SharedClass/db.h"
#include "node.h"
#include "bignode.h"
#include "../SharedClass/callersound.h"
#include "RemoteDisplay/remotedisplay.h"

class DisplayServer : public QObject
{
    Q_OBJECT
public:
    explicit DisplayServer(DB *db, BigNode *bigNode, QObject *parent = 0);
    ~DisplayServer();

    void test();
    void testDisconnect();

    void setStatusBarWidget(StatusBarWidget *statusBarWidget);

signals:

public slots:
    void slotNewConnection();
    void slotReadyRead();
    void slotSoundFinish();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
//    bool m_init;
//    bool m_busy;
//    QString m_msg;
    DB *m_db;
    NDHelper m_dt;
    RDHelper m_rd;
    Node *m_node;
    BigNode *m_bigNode;
    CallerSound *m_callerSound;
    RemoteDisplay *m_remoteDisplay;
    StatusBarWidget *m_statusBarWidget;

};

#endif // DISPLAYSERVER_H
