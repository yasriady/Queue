#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    MainWindowBase(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_process = new QProcess(this);

}

MainWindow::~MainWindow()
{
    delete m_process;
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{

//    QGridLayout *gridLayout1 = (QGridLayout*)ui->nodes->layout(); //new QGridLayout(ui->frame_2);
//    QGridLayout *gridLayout2 = new QGridLayout();
//    const int nodeQty = 10;
//    int colNum = 5;
//    int rowNum = (int) (nodeQty / colNum);
//    int nodeIdx= 0;
//    for(int row = 1; row <= rowNum; row++) {
//        for(int col = 1; col <= colNum; col++) {
//            QString nodeName = QString(QString::number(++nodeIdx).rightJustified(2, '0'));
//            nodeName.insert(0, "NODE_");
//            Node *node = new Node(nodeName, m_db, this);
//            connect( node, SIGNAL(signalLog(QString)), this, SLOT(slotLogger(QString)) );
//            gridLayout2->addWidget(node, row, col);
//            node->setBigNode(ui->bigNode);
//        }
//    }
//    gridLayout1->addLayout(gridLayout2, rowNum, colNum);

    makeNodes( (QGridLayout*)ui->nodes->layout(), ui->bigNode );

    mkCONFIG; mkCONFIX;
    const QString &orgAddress = confg->string(KEY("orgAddress"), "orgAddress");
    const QString &orgTitle = confg->string(KEY("orgTitle"), "orgTitle");
    ui->orgTitle->setText( orgTitle );
    ui->orgAddress->setText( orgAddress);
    QString pixName = confx->string( KEY("mainPic")  );
    QPixmap pixmap(pixName);
    ui->mainPic->setPixmap(pixmap);

    ui->orgAddress->hide();
    ui->menubar->hide();
    ui->statusbar->hide();
    int swIdx = confx->integr( KEY("stackedWidget"), 0 );
    ui->stackedWidget->setCurrentIndex( swIdx );

    //launchQClient();

    MainWindowBase::showEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_process->kill();
    MainWindowBase::closeEvent(event);
}

void MainWindow::slotLogger(const QString &text)
{
    LOGGER(text);
}

void MainWindow::slotSoundFinish()
{
    __PF__;
    m_busy = false;
}

void MainWindow::slotProcessClosed()
{
    __PF__;
}

void MainWindow::launchQClient()
{
    //    QProcess process;
    //    QString file = "/home/dedy/QtProjects/Queue/build-QClient-Desktop_Qt_5_7_0_GCC_64bit-Debug/QClient";
    //    process.startDetached(file);

    // http://stackoverflow.com/questions/18640485/launching-a-program-inside-another-program?rq=1&

    mkCONFIX;
    const QString &program = confx->string( KEY("programQClient") );
    //connect( process, SIGNAL(finished(int)), SLOT(finished()) );
    //connect( process, SIGNAL(error(QProcess::ProcessError)), SLOT(finished()) );
    connect( m_process, SIGNAL(aboutToClose()), this, SLOT(slotProcessClosed()) );

    m_process->start(program);
}

