//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <MainWindow/dmainwindow.h>
#include "../QDisplay/db.h"
#include "ticket.h"
#include <Inc/PushButton>
#include <Inc/CallerSound>

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
    void on_pushButton_clicked();
    void slotMakeTicket();

private:
    Ui::MainWindow *ui;
    M_DB;
    Ticket *m_ticket;
    DCallerSound *m_sound;

};

#endif // MAINWINDOW_H
