#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include "DMainWindow/dmainwindow.h"
#include "../db.h"
#include <QPushButton>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;
    DB *m_db;
    QPushButton *m_button;
    bool m_busy;

private slots:
    void slotMakeTicket();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    };

#endif // MAINWINDOW2_H
