//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef NODEA_H
#define NODEA_H

#include <QFrame>
#include <QDebug>
#include "db.h"
#include <server.h>
#include <QTcpSocket>
#include "socket.h"
#include "rdhelper.h"
#include "ndhelper.h"
#include <Inc/Widget>

namespace Ui {
class NodeA;
}

class NodeA : public DWidget
{
    Q_OBJECT

public:
    //explicit NodeA(QWidget *parent = 0);
    explicit NodeA(const QString &objName, DB* db, QWidget *parent = 0);
    ~NodeA();

private:
    Ui::NodeA *ui;
    DB *m_db;
    //NodeData m_dt;
    NDHelper m_dt;

    void updateUi();

    const QString nodeName();

public:
    NDHelper clientConnected(const RDHelper &rd);

protected:
    void showEvent(QShowEvent *event);

signals:
    void signalLog(const QString &text);

};

#endif // NODEA_H
