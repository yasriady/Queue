//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>

class Socket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = Q_NULLPTR);
    //virtual ~Socket();

};

#endif // SOCKET_H
