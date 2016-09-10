#ifndef DISPLAYSERVER_H
#define DISPLAYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "config.h"
#include "ndhelper.h"
#include "rdhelper.h"
#include "app_globals.h"
//#include "node.h"
//#include "bignode.h"
#include "callersound.h"
#include "remotedisplay.h"

class DisplayServer : public QObject
{
    Q_OBJECT
public:
    explicit DisplayServer(QObject *parent = 0);
    ~DisplayServer();

    //void setStatusBarWidget(StatusBarWidget *statusBarWidget);
    RemoteDisplay *remoteDisplay() const;

signals:
    void signalDataReady(NDHelper dt);
    void signalLog(QString string);

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
//    DB *m_db;
    NDHelper m_dt;
    RDHelper m_rd;
    //Node *m_node;
    //BigNode *m_bigNode;
    CallerSound *m_callerSound;
    RemoteDisplay *m_remoteDisplay;
    //StatusBarWidget *m_statusBarWidget;

};

#endif // DISPLAYSERVER_H
