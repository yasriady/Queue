#ifndef NODE_H
#define NODE_H

#include "BaseUi/nodebase.h"

namespace Ui {
class Node;
}

class Node : public NodeBase
{
    Q_OBJECT

public:
    explicit Node(const QString &nodeName, QWidget *parent = 0);
    ~Node();

    //void initData();
    //void updateUi(NDHelper &dt);

};

#endif // NODE_H

