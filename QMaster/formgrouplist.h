#ifndef FORMGROUPLIST_H
#define FORMGROUPLIST_H

#include <QWidget>

namespace Ui {
class FormGroupList;
}

class FormGroupList : public QWidget
{
    Q_OBJECT

public:
    explicit FormGroupList(QWidget *parent = 0);
    ~FormGroupList();

private:
    Ui::FormGroupList *ui;
};

#endif // FORMGROUPLIST_H
