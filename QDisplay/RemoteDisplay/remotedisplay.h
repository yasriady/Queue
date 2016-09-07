#ifndef REMOTEDISPLAY_H
#define REMOTEDISPLAY_H

#include <QObject>
#include "../SharedClass/config.h"
#include <dsettings.h>
#include "../SharedClass/server.h"
#include "../SharedClass/ndhelper.h"
#include "QTcpSocket"
#include "../SharedClass/StatusBar/statusbarwidget.h"

class RemoteDisplay : public QObject
{
    Q_OBJECT
public:
    explicit RemoteDisplay(QObject *parent = 0);
    ~RemoteDisplay();

    void send(const NDHelper &dt);
    void setStatusBarWidget(StatusBarWidget *statusBarWidget) { m_statusBarWidget = statusBarWidget; }
    void disconnectClient();

signals:

public slots:

private Q_SLOTS:
    void slotNewConnection();
    void slotSocketError( QAbstractSocket::SocketError error);
    void slotSocketDisconnected();

private:
    Server *m_tcpServer;
    QMap<QTcpSocket*, QTcpSocket*> m_clientList;
    StatusBarWidget *m_statusBarWidget;

};

#endif // REMOTEDISPLAY_H
