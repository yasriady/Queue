#ifndef NODEBASE_H
#define NODEBASE_H

#include <QWidget>
#include <Inc/Widget>
#include "../SharedClass/db.h"
#include "../SharedClass/ndhelper.h"

namespace Ui {
class NodeBase;
}

class NodeBase : public DWidget
{
    Q_OBJECT

public:
    explicit NodeBase(QWidget *parent = 0);
    ~NodeBase();

    void setNodeName(const QString &nodeName) { m_nodeName = nodeName; setObjectName(m_nodeName); }
    void updateUi(NDHelper &dt);

    const NDHelper &dt() const;

protected:
    Ui::NodeBase *ui;
    DB *m_db;
    NDHelper m_dt;
    QString m_nodeName;

};

#endif // NODEBASE_H
