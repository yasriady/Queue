#ifndef NODECHILD_H
#define NODECHILD_H

#include <QObject>
#include "node.h"

class NodeChild : public Node
{
    Q_OBJECT
public:
    explicit NodeChild(QWidget *parent = 0);
    ~NodeChild();
};

#endif // NODECHILD_H
