#ifndef CLASSHELPER_H
#define CLASSHELPER_H

#include "db.h"

class ClassHelper
{
public:
    explicit ClassHelper(NodeData *dt, DB *db);

    void A(char *param, QString value, size_t size);
    void A(uint16_t &param, uint16_t value);
    void A(uint8_t &param, uint8_t value);
    void A(bool &param, bool value);

    const QString S(const QVariant &var);

private:
    DB *m_db;
    NodeData *m_dt;

};

#endif // CLASSHELPER_H
