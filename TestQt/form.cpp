#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    DWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    customInit(this, "Form1", "Form1", true);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    toggleVisibility();
}
