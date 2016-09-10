#ifndef BIGNODE_H
#define BIGNODE_H

#include "BaseUi/bignodebase.h"

namespace Ui {
class BigNode;
}

class BigNode : public BigNodeBase
{
    Q_OBJECT

public:
    explicit BigNode(QWidget *parent = 0);
    ~BigNode();

protected:
    virtual void customInit();


};

#endif // BIGNODE_H
