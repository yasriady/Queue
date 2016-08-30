//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, Aug 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <MainWindow/mainwindowbase.h>
#include <Testing/Thread/dialogthread.h>
#include <Testing/Sound/mysound.h>

#include <Testing/dialogtesting.h>
#include <QSoundEffect>
#include <qtlibmainwindow.h>
#include <QSound>
#include <QtDebug>
#include <CallerSound/callersound.h>
#include <Testing/Painter/dialogpainter.h>
#include <QProcess>
#include <QScopedPointer>
#include <QPrintServer/printserver.h>
#include <QWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public MainWindowBase
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Q_SLOT void launchQClient();
    PrintServer *m_printServer;
    QProcess *m_process;

private slots:
    //void slotNewConnection();
    //void slotReadyRead();
    void slotLogger(const QString &text);
    virtual void slotSoundFinish();
    void slotProcessClosed();

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
