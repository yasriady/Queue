#include "mainwindowbase.h"
#include "ui_mainwindowbase.h"

MainWindowBase::MainWindowBase(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindowBase)
{
    ui->setupUi(this);
    m_db = new DB();
    makeNodes();

    // set verticalStretch
    mkCONFIX;
    int nodesVerticalStretchFactor = confx->integr( KEY("nodesVerticalStretchFactor"), 55);
    QSizePolicy sizePolicy_ = sizePolicy();
    sizePolicy_.setVerticalStretch(nodesVerticalStretchFactor);
    ui->nodes->setSizePolicy(sizePolicy_);

}

MainWindowBase::~MainWindowBase()
{
    delete ui;
}

void MainWindowBase::makeNodes()
{
    QVBoxLayout *layout1 = (QVBoxLayout*) ui->nodes->layout();
    QGridLayout *layout2 = new QGridLayout();
    const int nodeQty = 10;
    int colNum = 5;
    int rowNum = (int) (nodeQty / colNum);
    int nodeIdx= 0;
    for(int row = 1; row <= rowNum; row++) {
        for(int col = 1; col <= colNum; col++) {
            QString nodeName = QString(QString::number(++nodeIdx).rightJustified(2, '0'));
            nodeName.insert(0, "NODE_");
            Node *node = new Node(nodeName, m_db, this);
            //connect( node, SIGNAL(signalLog(QString)), this, SLOT(slotLogger(QString)) );
            layout2->addWidget(node, row, col);
        }
    }
    layout1->addLayout(layout2, 1);
}
