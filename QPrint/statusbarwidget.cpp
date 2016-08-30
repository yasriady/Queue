#include "statusbarwidget.h"
#include "ui_statusbarwidget.h"

StatusBarWidget::StatusBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBarWidget)
{
    ui->setupUi(this);
    ui->progressBar->hide();
}

StatusBarWidget::~StatusBarWidget()
{
    delete ui;
}

bool StatusBarWidget::connPixmap() const
{
    return m_connected;
}

void StatusBarWidget::setConnPixmap(bool connected)
{
    m_connected = connected;
    // ------ connIndicator Pixmap
    const QString &pngDisconnected = QString::fromUtf8(":/icon/png_16/network-disconnect.png");
    const QString &pngConnected    = QString::fromUtf8(":/icon/png_16/network-server-database.png");
    const QString &png             = (m_connected==true) ? pngConnected : pngDisconnected;
    const QPixmap &pixmap(png);
    ui->connPixmap->setPixmap(pixmap);

}

bool StatusBarWidget::connText() const
{
    return m_connected;
}

void StatusBarWidget::setConnText(bool connected)
{
    // ------ connIndicator Text
    m_connected = connected;
    const QString &text = mkTEXT(m_connected);
    ui->connText->setText  ( text );}

int StatusBarWidget::progressValue() const
{
    return m_progressValue;
}

void StatusBarWidget::setProgressValue(int progressValue)
{
    // ------ progressBar
    m_progressValue = progressValue;
    ui->progressBar->setValue   ( m_progressValue );
}

QString StatusBarWidget::dbBackend() const
{
    return m_dbBackend;
}

void StatusBarWidget::setDbBackend(const QString &dbBackend)
{
    // ------ dbBackend
    m_dbBackend = dbBackend;
    ui->dbBackend->setText      ( m_dbBackend );
}

void StatusBarWidget::UpdateUi()
{

}

