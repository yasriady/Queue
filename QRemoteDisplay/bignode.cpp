#include "bignode.h"
#include "ui_bignodebase.h"

BigNode::BigNode(QWidget *parent) :
    BigNodeBase(parent)
{
    qDebug() << objectName();
}

BigNode::~BigNode()
{
}

void BigNode::customInit()
{
    m_windowName = "BigNode";
    //setWindowTitle("");
}
