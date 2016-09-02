//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : application configuration, c/c++, Qt application
//--------------------------------------------------------

#ifndef CONFIG_H
#define CONFIG_H

//#include <QDir>
//#include <QApplication>
//#include <QDateTime>

// Arduino ---

#define MYSSID						"SSID2"
#define MY_PWD						"5422f891"
#define SERVER_PORT					9000
#define SERVER_IP					"192.168.1.2"

// PC --------

#define DISPLAYSERVER               confg->string( KEY("DisplayServer"), "192.168.1.2")
#define DISPLAYSERVERPORT           confg->integr( KEY("DisplayServerPort"), 9000)
#define REMOTEDISPLAYPORT           confg->integr( KEY("DisplayServerPort"), 9100)

// Taxonomy code
#define ERR_SRVBUSY                 "ERR_SRVBUSY"
#define ERR_NOTREGISTERED           "ERR_NOTREGISTERED"

#define GroupList                   "GroupList"
#define NodeList                    "NodeList"
#define PrintedQueue                "PrintedQueue"
#define MAXCALL                     2

#define  LOGIN_                     "LOGIN"
#define  CALLING_                   "CALL"
#define  PROCESS_                   "PROCESS"

#define REQUEST_                    "REQUEST"
#define REQUESTTEXT(expr)           m_db->getTaxonomy( REQUEST_, expr )

//#define EXTERADIR           QApplication::applicationDirPath() + QDir::separator() + "Extra" + QDir::separator()
//#define TICKETFORMAT        QString( "%1-%2").arg(groupCode).arg( queueNo.toInt() , 3, 10, QChar('0') )
//#define TICKETFORMAT        QString( "%1-%2").arg(groupCode).arg( queueNo , 3, 10, QChar('0') )
#define TICKET(expr1, expr2)    QString( "%1%2").arg(expr1).arg(expr2)
#define TICKET2                 QString( "%1%2").arg( m_dt.groupCode ).arg(m_dt.queueNo)

enum REQUEST {
    INIT=0, LOGIN, CALLING, PROCESS, PING
};

enum SRVANSWER {
    INITOK=0, REQUESTOK, SRVBUSY, NOTREGISTERED, ERROR
};

enum CLIREQUEST {
    CLI_INIT=0, CLI_LOGIN, CLI_CALLING, CLI_PROCESS, CLI_PING
};

enum QUEUESTATUS {
    WAITING, ONCALLED, PROCESSED
};

enum NODESTATUS {
    LOGGED_IN2, CALLING2, SERVING2, PING2
};


//typedef uint8_t byte;

#define setSTRING(dst, src)              strncpy( dst, src.toUtf8(), sizeof(dst) )
#define STRING(expr)                  QString( expr )

class NodeData {

public:
    // fixed
    char        macAddress[18]      = "                 ";                  // 11:22:33:AA:BB:CC
    char        nodeName[8]         = "       ";                            // NODE_01
    uint8_t     nodeId              = 0;                                    // 1
    char        displayedName[11];                         // LOKET 01
    char        ipAddressClient[16] = "192.168.xxx.xxx";                    // 192.168.100.001, -> reserved
    char        groupCode[2]        = "-";                                  // A
    uint8_t     portNo              = 0;                                    // 9000, -> reserved
    char        opr[18]             = "-----------------";                  // reserved
    char        service[32];                  // example: "Customer Service"
    // var
    uint8_t     request             = REQUEST::INIT;
    char        requestText[12];
    uint8_t     clientRequest       = CLIREQUEST::CLI_INIT;          //
    char        clientRequest_s[12]     = "       ";                            // CALL, PROCESS
    uint8_t     serverAnswer;
    char        serverAnswer_s[8];
    uint16_t    queueNo             = 0;                                   // type safe data type, lebih aman untuk memastikan panjang data sama disetiap system yang digunakan, yaitu 16 bit. Pada arduino juga.
    char        queueNo_s[32];
    char        message[32]         = "-----------------";                  // ?
    bool        connected           = false;                                // reserved
    bool        busy                = false;                                // reserved
    bool        RESULT              = false;                                // reserved
    uint8_t     count               = 0;                                    // reserved
    uint8_t     calledCount         = 0;                                    // ex: 1
    char        date_s[11]            = "1970-01-01";                         // reserved
    char        callingTime_s[20]     = "1970-01-01 00:00:00";
    char        processTime_s[20]     = "1970-01-01 00:00:00";
    uint16_t    numOfWaiting        = 0;

};

class RequestData {
public:
    char        macAddress[18];
    uint8_t     request              = REQUEST::INIT;

};




#endif // CONFIG_H
