#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BaseUi/mainwindowbase.h"
#include "displayserver.h"
#include "db.h"
#include "StatusBar/statusbarwidget.h"
#include "node.h"

class MainWindow : public MainWindowBase
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    StatusBarWidget *m_statusBarWidget;
    DisplayServer *m_displayServer;
    //RemoteDisplay *m_remoteDisplay;
    void updateUi();

protected:
    //void customInit();
    void on_pushButton_CONNECT_clicked();
    void on_pushButton_DISCONNECT_clicked();
    void on_pushButton_WRITEBACK_clicked();

public Q_SLOTS:
    void slotDataReady(NDHelper dt);
    void slotConnectionInfo(QString string);


};

#endif // MAINWINDOW_H
