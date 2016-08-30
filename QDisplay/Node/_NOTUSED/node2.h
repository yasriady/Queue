#ifndef NODE2_H
#define NODE2_H

#include <QWidget>

namespace Ui {
class Node2;
}

class Node2 : public QWidget
{
    Q_OBJECT

public:
    explicit Node2(QWidget *parent = 0);
    ~Node2();

private:
    Ui::Node2 *ui;

    void test();
};

#endif // NODE2_H
