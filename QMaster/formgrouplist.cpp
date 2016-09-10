#include "formgrouplist.h"
#include "ui_formgrouplist.h"

FormGroupList::FormGroupList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGroupList)
{
    ui->setupUi(this);
}

FormGroupList::~FormGroupList()
{
    delete ui;
}
