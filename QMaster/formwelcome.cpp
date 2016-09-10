#include "formwelcome.h"
#include "ui_formwelcome.h"

FormWelcome::FormWelcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormWelcome)
{
    ui->setupUi(this);
}

FormWelcome::~FormWelcome()
{
    delete ui;
}
