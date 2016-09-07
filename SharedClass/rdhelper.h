//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef RDHELPER_H
#define RDHELPER_H

#include <QObject>
#include "../SharedClass/config.h"

#define RD               m_rd->rd()

class RDHelper
{
public:
    RDHelper();
    ~RDHelper();

    QString macAddress() const;
    void setMacAddress(const QString &macAddress);

    REQUEST request() const;
    void setRequest(const REQUEST &request);

    RequestData *rd() const;
    void setRd(RequestData *rd);

private:
    RequestData *m_rd;

//    QString     m_macAddress;
//    REQUEST  m_request;//              = (uint8_t)CLIREQUEST::CLI_INIT;

};

#endif // RDHELPER_H
