#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../SharedClass/BaseUi/mainwindowbase.h"
#include "displayserver.h"
#include "../SharedClass/db.h"
#include "../SharedClass/StatusBar/statusbarwidget.h"

class MainWindow : public MainWindowBase
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    DisplayServer *m_displayServer;
    StatusBarWidget *m_statusBarWidget;

protected:
    void customInit();
    void on_pushButton_CONNECT_clicked();
    void on_pushButton_DISCONNECT_clicked();
    void on_pushButton_WRITEBACK_clicked();


};

#endif // MAINWINDOW_H
