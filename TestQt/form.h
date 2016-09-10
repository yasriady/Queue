#ifndef FORM_H
#define FORM_H

//#include <QWidget>
#include <Inc/Widget>

namespace Ui {
class Form;
}

class Form : public DWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
