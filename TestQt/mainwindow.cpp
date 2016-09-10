#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customInit(this, "MainWindow", "MainWindow", true);

    m_callerSound = new DCallerSoundAlsa();
    m_db = new DBManager();

}

MainWindow::~MainWindow()
{
    delete m_callerSound;
    delete ui;
}

void MainWindow::coba2()
{
    //m_int = new qint32();
    //qDebug() << m_int;
    //m_int++;
    //qDebug() << m_int;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
}

void MainWindow::on_pushButton_PlayWithAlsa_clicked()
{
    m_callerSound->call("dua");
    //QStringList data;
    //data << "satu";
    //m_callerSoundThread->call(data);
}

void MainWindow::on_pushButton_ReadWAVHeader_clicked()
{
    WavFile *wavFile = new WavFile("/satu.wav");
    QString str = QString( "%1" ).arg( wavFile->getSampleRate() );
    qDebug( str.toUtf8() );
}

void MainWindow::on_pushButton_aplay_clicked()
{
    //m_callerSound->call("satu");
    m_callerSound->call("lima");
}

//void MainWindow::customInit()
//{
//    m_windowName = "MainWindow";
//    setWindowTitle("Test");
//}

void MainWindow::on_pushButton_4_clicked()
{
    ui->dRunningText->start();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->dRunningText->loop();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->dRunningText->setTextRunning("Daffa dan Azzam, dan Mama");
}

void MainWindow::on_pushButton_7_clicked()
{
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->dRunningText->setDb(m_db);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->dRunningText->stop();
}

void MainWindow::on_pushButton_10_clicked()
{
    __PF(objectName());
}

void MainWindow::on_pushButton_11_clicked()
{
    Form *f = new Form();
    f->show();
    //f->toggleVisibility(f);
}
