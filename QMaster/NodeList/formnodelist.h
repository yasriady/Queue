#ifndef FORMNODELIST_H
#define FORMNODELIST_H

#include <QWidget>

namespace Ui {
class FormNodeList;
}

class FormNodeList : public QWidget
{
    Q_OBJECT

public:
    explicit FormNodeList(QWidget *parent = 0);
    ~FormNodeList();

private:
    Ui::FormNodeList *ui;

};

#endif // FORMNODELIST_H
