#include "node2.h"
#include "ui_node2.h"

Node2::Node2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node2)
{
    ui->setupUi(this);
}

Node2::~Node2()
{
    delete ui;
}

void Node2::test()
{
//    char lcdLine1[16];
//    strcpy(lcdLine1, "Callilng ");
//    strcat(lcdLine1, dt.queueNo_);
//    //strcat()

//    //char lcdLine2[16];
//    std::string stdStr;
//    stdStr = "A";
}
