#include "db.h"

DB::DB()
    : DBManager()
{
}

DB::~DB()
{
}

void DB::test()
{
    qDebug() << __PRETTY_FUNCTION__;
}

const QString DB::getNodeName(const QString &macAddress)
{
    //const QString &sql = " SELECT * FROM NodeList WHERE mac_address='A6:DF:8B:7D:DD:CF'; ";
    //QString nodeName = getText( sql, "node_name");
    QString nodeName = getText("node_name", NodeList, "mac_address='" + macAddress + "'");
    return ( nodeName=="" ? NOTFOUND : nodeName) ;
}

const QString DB::getDisplayedName(const QString &nodeName)
{
    QString displayName = getText("displayed_name", NodeList, "node_name='" + nodeName + "'");
    return ( displayName=="" ? NOT_REGISTERED : displayName) ;
}

const QString DB::getGroupCode(const QString &nodeName)
{
    QString groupCode = getText("group_code", NodeList, "node_name='" + nodeName + "'");
    return ( groupCode == "" ? NA : groupCode) ;
}

const QString DB::getService(const QString &groupCode)
{
    QString groupAssignment = getText("service", GroupList, "group_code='" + groupCode + "'");
    return ( groupAssignment == "" ? NA : groupAssignment) ;
}

const QString DB::getStatus(const QString &nodeName)
{
    QString status = getText("status", NodeList, "node_name='" + nodeName + "'");
    return ( status == "" ? NA : status) ;
}

const QString DB::getMacAddress(const QString &nodeName)
{
    QString macAddress = getText("mac_address", NodeList, "node_name='" + nodeName + "'");
    return ( macAddress == "" ? NA : macAddress) ;
}

uint8_t DB::getNodeId(const QString &nodeName)
{
    QString nodeId = getText("node_id", NodeList, "node_name='" + nodeName + "'");
    return ( nodeId == "" ? 0 : nodeId.toInt() ) ;
}

uint8_t DB::getPortNo(const QString &nodeName)
{
    QString portNo = getText("port_no", NodeList, "node_name='" + nodeName + "'");
    return ( portNo == "" ? 0 : portNo.toInt() ) ;
}

// get current queueNo from NodeList table
uint16_t DB::getQueueNo_1(const QString &nodeName)
{
    QString queueNo = getText("queue_no", NodeList, "node_name='" + nodeName + "'");
    return ( queueNo == "" ? 0 : queueNo.toInt() ) ;
}

// get current queueNo
MyMap DB::getQueueNo(const QString &nodeName)
{
    MyMap rcd;
    // get queueNo currently processed by this NODE (atau yang paling last?)
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE ( processed_by='%1' ) ORDER BY rowidx DESC LIMIT 1; " ).arg(nodeName);
    //sql = " SELECT * FROM v_PrintedQueue where processed_by='DAFFA'; ";
    //qDebug() << sql;
    rcd = getRecord1(sql);
    return rcd;
}

MyMap DB::getNextQueueNo(const QString &nodeName)
{
    MyMap rcd;
    QString groupCode = getGroupCode(nodeName);

    // get queueNo currently processed by this NODE
    QString sql = QString( "SELECT * FROM v_PrintedQueue WHERE ( ( processed_by='%1' ) AND ( status=%2 ) AND ( called_count<%3 ) )  ;" ).arg(nodeName).arg( (int)QUEUESTATUS::ONCALLED ).arg( MAXCALL );
    rcd = getRecord1(sql);

    if( rcd.size() == 0 ) {  // NOT found ONCALLED
        // look for next WAITING
        sql = QString( "SELECT * FROM v_PrintedQueue WHERE ( ( group_code='%1' ) AND ( status=%2 ) ) ORDER BY rowidx ASC LIMIT 1 ;" ).arg(groupCode).arg( (int)QUEUESTATUS::WAITING );
        rcd = getRecord1(sql);
    }

    // update status, called_count, processed_by
    int status = (int)QUEUESTATUS::ONCALLED;
    int calledCount = rcd["called_count"].toInt() + 1;
    QString processedBy = nodeName;
    int rowIdx = rcd["rowidx"].toInt();
    sql = QString( " UPDATE PrintedQueue SET status=%1, called_count=%2, processed_by='%3' WHERE rowidx=%4 " ).arg(status).arg(calledCount).arg(processedBy).arg(rowIdx);
    updateRecord(sql);
    qDebug() << sql;
    return rcd;
}

uint8_t DB::getCalledCount(const QString &nodeName)
{
    // ? Error, query not correct yet
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE processed_by='%1' " ).arg(nodeName);
    MyMap rcd = getRecord1(sql);
    uint8_t calledCount = (uint8_t) rcd["called_count"].toInt();
    return calledCount;
}

uint16_t DB::getMaxQueueNo(const QString &groupCode)
{
    QString queueNo = getText( "MAX(queue_no)", "v_PrintedQueue", "group_code='" + groupCode + "'" );
    return ( queueNo == "" ? 0 : queueNo.toInt() ) ;

}

const QJsonObject DB::getLastPrintedQueue()
{
    const QString &sql = QString( " SELECT *, DATE(ts) AS date, TIME(ts) AS time FROM v_PrintedQueue ORDER by rowidx DESC LIMIT 1 " );
    QJsonObject rcds = getRecord3(sql);
    QJsonObject rcd = (rcds["0"]).toObject();
    return rcd;
}

const QJsonObject DB::getPrintedQueue(const QString &groupCode, const int &queueNo)
{
    const QString &sql = QString( " SELECT * FROM v_PrintedQueue WHERE group_code='%1' AND queue_no=%2 " ).arg(groupCode).arg(queueNo);
    QJsonObject rcds = getRecord3(sql);
    QJsonObject rcd = (rcds["0"]).toObject();
    return rcd;
}

uint16_t DB::getNumOfWaiting(const QString &groupCode)
{
    const QString &sql = QString( " SELECT COUNT(queue_no) AS cnt FROM v_PrintedQueue WHERE status=0 and group_code='%1' " ).arg(groupCode);
    QJsonObject rcds = getRecord3(sql);
    QJsonObject rcd = (rcds["0"]).toObject();
    //int number = (rcd["cnt"].toVariant()).toInt();

    // Error build at Rpi2
    int number = (rcd["cnt"].toString()).toInt();

    return number;
}

const QJsonObject DB::getNodeInfo(const QString &macAddress)
{
    const QString &sql = QString( " SELECT * FROM v_NodeList WHERE mac_address='%1' " ).arg(macAddress);
    QJsonObject rcds = getRecord3(sql);
    QJsonObject rcd = (rcds["0"]).toObject();
    return rcd;
}

const QJsonObject DB::getNodeInfoByName(const QString &nodeName)
{
    const QString &sql = QString( " SELECT * FROM v_NodeList WHERE node_name='%1' " ).arg(nodeName);
    return this->getRecordBySql(sql);
}

const QJsonObject DB::getRecordBySql(const QString &sql)
{
    QJsonObject rcds = getRecord3(sql);
    QJsonObject rcd = (rcds["0"]).toObject();
    return rcd;
}

const QString DB::getOpr(const QString &nodeName)
{
    QString opr = getText("operator_name", NodeList, "node_name='" + nodeName + "'");
    return ( opr == "" ? 0 : opr ) ;
}

MyMap DB::doLogin(const QString &nodeName)
{
    MyMap rcd = this->getLastQueue(nodeName);
    return rcd;
}

MyMap DB::doCalling(const QString &nodeName)
{
    const QString &groupCode = getGroupCode(nodeName);

    // querying of "ONCALLED queueNo"
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE processed_by='%1' AND status=%2 AND called_count<%3 ORDER BY rowidx DESC LIMIT 1 " ).arg(nodeName).arg(QUEUESTATUS::ONCALLED).arg(MAXCALL);
    MyMap rcd = this->getRecord1(sql);
    if( rcd.size()==0 ) {
        // if ONCALLED queueNo above not found, then query for WAITING queueNo based on groupCode
        sql = QString( " SELECT * FROM v_PrintedQueue WHERE group_code='%1' AND status=%2 ORDER BY rowidx ASC LIMIT 1 " ).arg(groupCode).arg(QUEUESTATUS::WAITING);
        rcd = this->getRecord1(sql);
    }

    int rowIdx = rcd["rowidx"].toInt();
    int calledCount = rcd["called_count"].toInt() + 1;

    QString callTime = rcd["calling_time"].toString();
    callTime = (calledCount==1) ? CURDATETIME_ : callTime;
    // update status=called_count+1
    sql = QString( " UPDATE PrintedQueue SET status=%1, called_count=%2, processed_by='%3', calling_time='%5' WHERE rowidx=%4 " ).arg(QUEUESTATUS::ONCALLED).arg(calledCount).arg(nodeName).arg(rowIdx).arg(callTime);
    updateRecord(sql);

    // renew rcd, retrieved by rowidx
    sql = QString( " SELECT * FROM  v_PrintedQueue WHERE rowidx=%1 " ).arg(rowIdx);
    rcd = this->getRecord1(sql);

    return rcd;
}

MyMap DB::doProcess(const QString &nodeName)
{
    MyMap rcd;
    // get queueNo currently processed by this NODE
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE ( processed_by='%1' ) ORDER BY rowidx DESC LIMIT 1 " ).arg(nodeName);
    rcd = getRecord1(sql);

    QString servTime_ = rcd["process_time"].toString();
    servTime_ = servTime_.length()==0 ? CURDATETIME_ : servTime_;

    int rowIdx = rcd["rowidx"].toInt();
    int status = rcd["status"].toInt();
    if( status != QUEUESTATUS::PROCESSED ) {
        // update status to QUEUESTATUS::PROCESSED
        sql = QString( " UPDATE PrintedQueue SET status=%1, process_time='%3' WHERE rowidx=%2 " ).arg(QUEUESTATUS::PROCESSED).arg(rowIdx).arg(servTime_);
        updateRecord(sql);
    }

    // renew rcd, retrieved by rowidx
    sql = QString( " SELECT * FROM  v_PrintedQueue WHERE rowidx=%1 " ).arg(rowIdx);
    rcd = this->getRecord1(sql);

    return rcd;

}

MyMap DB::doPing(const QString &nodeName)
{
    MyMap rcd = this->getLastQueue(nodeName);
    return rcd;
}

QJsonObject DB::getLastQueue2(const QString &nodeName)
{
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE rowidx= ( SELECT MAX(rowidx) FROM v_PrintedQueue WHERE processed_by='%1' ); " ).arg(nodeName);
    return this->getRecordBySql(sql);
}

MyMap DB::getLastQueue(const QString &nodeName)
{   // Get last record (current pending queueNo) processed by this nodeName
    MyMap rcd;
    QString sql = QString( " SELECT * FROM v_PrintedQueue WHERE rowidx= ( SELECT MAX(rowidx) FROM v_PrintedQueue WHERE processed_by='%1' ); " ).arg(nodeName);
    rcd = getRecord1(sql);
    return rcd;
}

MyMap DB::getQueueRecord2(const QString &nodeName)
{
    MyMap rcd;
    QString groupCode = getGroupCode(nodeName);

    // get queueNo currently processed by this NODE
    QString sql = QString( "SELECT * FROM v_PrintedQueue WHERE ( ( processed_by='%1' ) AND ( status=%2 ) AND ( called_count<%3 ) )  ;" ).arg(nodeName).arg( (int)QUEUESTATUS::ONCALLED ).arg( MAXCALL );
    rcd = getRecord1(sql);

    if( rcd.size() == 0 ) {  // NOT found ONCALLED
        // look for next WAITING
        sql = QString( "SELECT * FROM v_PrintedQueue WHERE ( ( group_code='%1' ) AND ( status=%2 ) ) ORDER BY rowidx ASC LIMIT 1 ;" ).arg(groupCode).arg( (int)QUEUESTATUS::WAITING );
        rcd = getRecord1(sql);
    }
    return rcd;
}
