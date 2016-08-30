#include "mainwindowa.h"
#include "ui_mainwindowa.h"

MainWindowA::MainWindowA(QWidget *parent) :
    MainWindowBase(parent),
    ui(new Ui::MainWindowA)
{
    ui->setupUi(this);
    init();

    mkCONFIX;
    QString picFilename = confx->string( KEY("mainPic")  );
    ui->mainPic->setPixmapFile(picFilename);

}

MainWindowA::~MainWindowA()
{
    delete ui;
}

void MainWindowA::showEvent(QShowEvent *event)
{
    makeNodesA(ui->nodes, ui->bigNode);
    ui->runningText->setDb(m_db);
    MainWindowBase::showEvent(event);
}

void MainWindowA::slotLogger(const QString &text)
{

}

void MainWindowA::on_rtStart_clicked()
{
    if( ui->runningText->isRunning() )
        ui->runningText->stopRunningText();
    else
        ui->runningText->startRunningText();
}

void MainWindowA::on_rtSetText_clicked()
{
    //const QString &msg = m_db->getTaxonomy(RUNNINGTEXT);
    //ui->runningText->setText(msg);
    //ui->runningText->setDb( m_db );

    char buf[4];
    int myval = 1;
    sprintf(buf, "%03d", myval);
    qDebug() << buf;

    //__PF(msg);
}
