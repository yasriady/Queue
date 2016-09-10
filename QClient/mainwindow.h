//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainWindow/dmainwindow.h"
#include "client.h"
#include <QtDebug>
#include <iterator>
#include <QThread>
#include <Label/dlabel.h>
#include <QLineEdit>
#include "globals.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;

    void makeNode();
    Client *client;
    QLineEdit *mac;
    QFrame *node;

protected:
    void showEvent(QShowEvent *event);

};

#endif // MAINWINDOW_H
