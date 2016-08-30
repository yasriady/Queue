#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow/dmainwindow.h>
#include "../db.h"
#include <QPushButton>
#include <DSettings/dsettings.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFile>
#include <print.h>
#include <QWindow>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MainWindow;
}

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DB *m_db;
    QPushButton *m_button;
    QList<QPushButton*> m_btnList;
    void setButton (const bool &enable);
    bool m_busy;
    Print *m_print;
    QMediaPlayer *m_mediaPlayer;
    QMediaPlaylist *m_mediaPlaylist;

protected:
    void showEvent(QShowEvent *event);


private slots:
    void on_pushButton_clicked();
    void slotMakeTicket();
    void slotMyTimer();

//    void TestingPrint1();
//    void TestingPrint2();

};

#endif // MAINWINDOW_H
