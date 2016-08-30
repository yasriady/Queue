//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, Aug 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOWBASE_H
#define MAINWINDOWBASE_H

#include <QObject>
#include <qgridlayout.h>
#include <Inc/MainWindow>
#include "server.h"
#include "socket.h"
#include <Inc/CallerSound>
#include "db.h"
#include "Node/nodea.h"
#include "ndhelper.h"
#include "rdhelper.h"
#include "bignode.h"

#define LOGGER(msg)     qDebug() << msg

class MainWindowBase : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowBase(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~MainWindowBase();

protected:
    Server *m_tcpServer;
    Socket *m_tcpSocket;
    bool m_busy;
    bool m_init;
    QString m_msg;
    DB *m_db;
    QString m_logStr;
    //NodeData m_dt;
    //RequestData m_rd;
    NDHelper m_dt;
    RDHelper m_rd;
    BigNode *m_bigNode;

    DCallerSound *m_callerSound;
    void makeSound(const NDHelper &dt);
    void makeNodes(QGridLayout *layout, BigNode *bigNode);
    void makeNodesA(QFrame *frame, BigNode *bigNode);

private slots:
    void slotNewConnection();
    void slotReadyRead();
    virtual void slotSoundFinish();

};

#endif // MAINWINDOWBASE_H
