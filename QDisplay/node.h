#ifndef NODE_H
#define NODE_H

#include "../SharedClass/BaseUi/nodebase.h"

namespace Ui {
class Node;
}

class Node : public NodeBase
{
    Q_OBJECT

public:
    explicit Node(const QString &nodeName, DB* db, QWidget *parent = 0);
    ~Node();

    void initData();
    //void updateUi(NDHelper &dt);

protected:
    virtual void customInit();

};

#endif // NODE_H

