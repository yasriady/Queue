#ifndef NODE_H
#define NODE_H

#include <QFrame>
#include <QDebug>
#include "db.h"
#include <server.h>
#include <QTcpSocket>
#include "socket.h"
#include "bignode.h"

namespace Ui {
class Node;
}

class Node : public QFrame
{
    Q_OBJECT

public:
    explicit Node(const QString &objName, DB* db, QWidget *parent = 0);
    explicit Node(QWidget *parent = 0);
    ~Node();

private:
    Ui::Node *ui;
    DB *m_db;
    NodeData m_dt;
    void initVar();
    void updateUi();
    const QPixmap makePixmap(const bool &connected);
    BigNode *m_bigNode;

public:
    void clientConnected(NodeData &nodeData, Socket *tcpSocket);
    void setBigNode(BigNode *bigNode);

protected:
    void showEvent(QShowEvent *event);

signals:
    void signalLog(const QString &text);


};

#endif // NODE_H
