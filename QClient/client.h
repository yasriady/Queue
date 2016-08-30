//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef CLIENT_H
#define CLIENT_H

#include <MainWindow/dmainwindow.h>
#include <QTcpSocket>
#include "mysocket.h"
#include <QNetworkInterface>
#include <QTimer>
#include <QMainWindow>
#include "../QDisplay/config.h"

#include <QFrame>
#include <QLabel>
#include <QThread>
#include <QLineEdit>
#include <QGraphicsDropShadowEffect>
#include "../QDisplay/ndhelper.h"
#include "../QDisplay/rdhelper.h"

namespace Ui {
class Client;
}

class Client : public DMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0, QLineEdit *mac = 0);
    ~Client();

private slots:
    void on_toolButton_Login_clicked();
    void on_toolButton_Logout_clicked();
    void on_toolButton_Ping_clicked();
    void slotReadyRead();
    void slotMyTimer();
    void on_actionExit_triggered();
    void on_actionLogin_triggered();
    void on_actionLogout_triggered();
    void on_calling_clicked();
    void on_process_clicked();

    void on_pushButton_clicked();

    void on_init_clicked();

private:
    Ui::Client *ui;

    QString m_hostName;
    quint16 m_port;
    MySocket *m_tcpSocket;
    NDHelper *m_dt;
    RDHelper *m_rd;

    bool m_simulationMode;
    QString m_macAddress;
    QString m_windowName;

//    bool m_connected;
//    QString m_message;
//    QString m_displayedName;
//    QString m_nodeName;
//    int m_queueNo;
//    QString m_GroupCode;
//    QString m_status;

    bool connectToHost();
    bool disconnectFromHost();

    void initVar();
    void updateUi();
    const QPixmap makePixmap(const bool &connected);

    void make(const REQUEST &request);

public:
    // Trivia
    QWidget *getWidget();
    void doLogin(); // meant to connect to server

};

#endif // CLIENT_H
