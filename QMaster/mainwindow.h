#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Inc/MainWindow>
#include "displayserver.h"
#include "StatusBar/statusbarwidget.h"
//#include "db.h"

#include "formwelcome.h"
#include "NodeList/formnodelist.h"
#include "formgrouplist.h"
#include "formreport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //DB *db() const;

private:
    Ui::MainWindow *ui;
    DisplayServer *m_displayServer;
    //DB *m_db;
    StatusBarWidget *m_statusBarWidget;
    void addNewTab();
    bool pageExist(const QString &formName);

public Q_SLOTS:
    void slotDataReady(NDHelper dt);
    void slotConnectionInfo(QString string);
    void slotLog(QString string);

private slots:
    void on_actionLogger_triggered();
    void on_cmdNodeList_clicked();
    void on_cmdGroupList_clicked();
    void on_cmdWelcome_clicked();
    void on_cmdReport_clicked();
    void on_tabWidget_tabCloseRequested(int index);


};

#endif // MAINWINDOW_H
