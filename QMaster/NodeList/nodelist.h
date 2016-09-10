#ifndef NODELIST_H
#define NODELIST_H

#include <QObject>
#include<QTreeWidget>
#include "globals.h"

class NodeList : public QTreeWidget
{
public:
    explicit NodeList(QWidget *parent = Q_NULLPTR);

private:
    int m_columnCount;
    void make();
};

#endif // NODELIST_H
