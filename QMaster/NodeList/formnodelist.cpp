#include "formnodelist.h"
#include "ui_formnodelist.h"

FormNodeList::FormNodeList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNodeList)
{
    ui->setupUi(this);
}

FormNodeList::~FormNodeList()
{
    delete ui;
}
