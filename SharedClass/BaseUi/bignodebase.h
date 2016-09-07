#ifndef BIGNODEBASE_H
#define BIGNODEBASE_H

#include <QWidget>
#include "../db.h"
#include <Inc/Widget>
#include "../SharedClass/ndhelper.h"

namespace Ui {
class BigNodeBase;
}

class BigNodeBase : public DWidget
{
    Q_OBJECT

public:
    explicit BigNodeBase(QWidget *parent = 0);
    ~BigNodeBase();

    void updateUi(NDHelper *dt);

protected:
    Ui::BigNodeBase *ui;

private:
    DB *m_db;

};

#endif // BIGNODEBASE_H
