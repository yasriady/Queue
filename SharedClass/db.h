//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef DB_H
#define DB_H

#include "../../QtLib/QtDB/dbmanager.h"
#include "config.h"

class DB : public DBManager
{
public:

    DB();
    ~DB();

    void test();

    const QString getNodeName(const QString &macAddress);
    const QString getDisplayedName(const QString &nodeName);
    const QString getGroupCode( const QString &nodeName );
    const QString getService( const QString &groupCode );
    const QString getStatus(const QString &nodeName);
    const QString getMacAddress(const QString &nodeName);
    uint8_t getNodeId(const QString &nodeName);
    uint8_t getPortNo(const QString &nodeName);
    uint16_t getQueueNo_1(const QString &nodeName);      // get current queueNo from NodeList table
    const QString getOpr(const QString &nodeName);

    MyMap doLogin(const QString &nodeName);
    MyMap doCalling(const QString &nodeName);
    MyMap doProcess(const QString &nodeName);
    MyMap doPing(const QString &nodeName);

    QJsonObject getLastQueue2(const QString &nodeName);
    MyMap getLastQueue(const QString &nodeName);
    MyMap getQueueRecord2(const QString &nodeName);

    MyMap getQueueNo(const QString &nodeName);        // get from PrintedQueue
    MyMap getNextQueueNo(const QString &nodeName);

    uint8_t getCalledCount(const QString &nodeName);
    uint16_t getMaxQueueNo(const QString &groupCode);

    const QJsonObject getLastPrintedQueue();
    const QJsonObject getPrintedQueue(const QString &groupCode, const int &queueNo);
    uint16_t getNumOfWaiting(const QString &groupCode);

    const QJsonObject getNodeInfo(const QString &macAddress);
    const QJsonObject getNodeInfoByName(const QString &nodeName);
    const QJsonObject getRecordBySql(const QString &sql);

};

#endif // DB_H
