#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    makeNode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeNode()
{

    QList<QFrame*> child = findChildren<QFrame*>(QRegExp("node_*"));
    QList<QFrame*>::iterator it;
    int i=0;
    for( it = child.begin(); it != child.end(); it++ )
    {
        node = (QFrame*) child.at(i);
        QString name = node->objectName();
        name.replace("node_", "mac_");
        mac = (QLineEdit*) findChild<QLineEdit*>(name);

        client = new Client(this, mac);
        node->layout()->addWidget( client );
        i++;
    }
}


void MainWindow::showEvent(QShowEvent */*event*/)
{
    ui->menubar->hide();
    ui->statusbar->hide();
}
