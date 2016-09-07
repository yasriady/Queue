#include "statusbarwidget.h"
#include "ui_statusbarwidget.h"

StatusBarWidget::StatusBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBarWidget)
{
    ui->setupUi(this);
    resetUi();
}

StatusBarWidget::~StatusBarWidget()
{
    delete ui;
}

void StatusBarWidget::setLabel1(const QString &text)
{
    ui->label1->setText(text);
}

void StatusBarWidget::setLabel2(const QString &text)
{
    ui->label2->setText(text);
}

void StatusBarWidget::setLabel3(const QString &text)
{
    ui->label3->setText(text);
}

void StatusBarWidget::setLabel4(const QString &text)
{
    ui->label4->setText(text);
}

void StatusBarWidget::setLabel5(const QString &text)
{
    ui->label5->setText(text);
}

void StatusBarWidget::setLabel6(const QString &text)
{
    ui->label6->setText(text);
}

void StatusBarWidget::setLabel7(const QString &text)
{
    ui->label7->setText(text);
}

void StatusBarWidget::resetUi()
{
    setLabel1("");
    setLabel2("");
    setLabel3("");
    setLabel4("");
    setLabel5("");
    setLabel6("");
    setLabel7("");
}
