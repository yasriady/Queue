#include "statusbarwidget.h"
#include "ui_statusbarwidget.h"

StatusBarWidget::StatusBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBarWidget)
{
    ui->setupUi(this);
}

StatusBarWidget::~StatusBarWidget()
{
    delete ui;
}

void StatusBarWidget::setConnected(const bool &connected)
{
    QString pngDisconnected = QString::fromUtf8(":/new/png_16x16/png_16x16/process-stop.png");
    QString pngConnected    = QString::fromUtf8(":/new/png_16x16/png_16x16/checkbox.png");
    QString png             = connected ? pngConnected : pngDisconnected;
    ui->connected->setPixmap(QPixmap(png));
}

void StatusBarWidget::setMessage(const QString &text)
{
    ui->message->setText(text);
}

void StatusBarWidget::setMacAddress(const QString &text)
{
    ui->macAddress->setText(text);
}

void StatusBarWidget::setGroupCode(const QString &text)
{
    ui->groupCode->setText(text);
}

void StatusBarWidget::setNodeName(const QString &text)
{
    ui->nodeName->setText(text);
}

void StatusBarWidget::setCalledCount(const int &calledCount)
{
    ui->calledCount->setText( QString::number(calledCount) );
}
