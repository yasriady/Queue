//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, Aug 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOWA_H
#define MAINWINDOWA_H

#include <MainWindow/mainwindowbase.h>

namespace Ui {
class MainWindowA;
}

class MainWindowA : public MainWindowBase
{
    Q_OBJECT

public:
    explicit MainWindowA(QWidget *parent = 0);
    ~MainWindowA();

private:
    Ui::MainWindowA *ui;

protected:
    virtual void showEvent(QShowEvent *event);

public Q_SLOTS:
    void slotLogger(const QString &text);

private slots:
    void on_rtStart_clicked();
    void on_rtSetText_clicked();
};

#endif // MAINWINDOWA_H
