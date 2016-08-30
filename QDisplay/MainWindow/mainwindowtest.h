//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, Aug 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOWTEST_H
#define MAINWINDOWTEST_H

#include <QMainWindow>

namespace Ui {
class MainWindowTest;
}

class MainWindowTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTest(QWidget *parent = 0);
    ~MainWindowTest();

private:
    Ui::MainWindowTest *ui;
};

#endif // MAINWINDOWTEST_H
