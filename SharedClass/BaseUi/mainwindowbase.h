#ifndef MAINWINDOWBASE_H
#define MAINWINDOWBASE_H

#include <Inc/MainWindow>
#include <QFrame>
#include <node.h>
#include "../db.h"

namespace Ui {
class MainWindowBase;
}

class MainWindowBase : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowBase(QWidget *parent = 0);
    ~MainWindowBase();

protected:
    Ui::MainWindowBase *ui;
    void makeNodes();
    DB* m_db;

private slots:
    virtual void on_pushButton_CONNECT_clicked() = 0;
    virtual void on_pushButton_WRITEBACK_clicked() = 0;
    virtual void on_pushButton_DISCONNECT_clicked() = 0;

private:

};

#endif // MAINWINDOWBASE_H
