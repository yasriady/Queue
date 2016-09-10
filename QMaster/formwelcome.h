#ifndef FORMWELCOME_H
#define FORMWELCOME_H

#include <QWidget>

namespace Ui {
class FormWelcome;
}

class FormWelcome : public QWidget
{
    Q_OBJECT

public:
    explicit FormWelcome(QWidget *parent = 0);
    ~FormWelcome();

private:
    Ui::FormWelcome *ui;
};

#endif // FORMWELCOME_H
