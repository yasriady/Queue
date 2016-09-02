#ifndef REMOTEDISPLAY_H
#define REMOTEDISPLAY_H

#include <QObject>
#include "../SharedClass/config.h"
#include <dsettings.h>
#include "../SharedClass/server.h"
#include "../SharedClass/socket.h"

class RemoteDisplay : public QObject
{
    Q_OBJECT
public:
    explicit RemoteDisplay(QObject *parent = 0);
    ~RemoteDisplay();

signals:

public slots:

private Q_SLOTS:
    void slotNewConnection();
    void slotReadReady();
    void slotSocketError( QAbstractSocket::SocketError );
    void slotSocketDisconnected();

private:
    Server *m_tcpServer;
    Socket *m_tcpSocket;
    QVector<RemoteDisplay*> m_availableRemoteDisplay;
    bool m_connected;

};

#endif // REMOTEDISPLAY_H
