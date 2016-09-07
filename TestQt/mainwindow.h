#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Inc/MainWindow>
#include <QtDebug>
#include <Inc/CallerSoundAlsa>
#include <CallerSoundAlsa/wavfile.h>
#include <Inc/DBManager>

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

    qint32 m_int;
    DCallerSoundAlsa *m_callerSound;
    DBManager *m_db;

private Q_SLOTS:
    void coba2();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_PlayWithAlsa_clicked();
    void on_pushButton_ReadWAVHeader_clicked();
    void on_pushButton_aplay_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

protected:
    virtual void customInit();

};

#endif // MAINWINDOW_H
