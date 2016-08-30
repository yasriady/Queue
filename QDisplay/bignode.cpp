#include "bignode.h"
#include "ui_bignode.h"

BigNode::BigNode(QWidget *parent) :
    DWidget(parent),
    ui(new Ui::BigNode)
{
    ui->setupUi(this);
    init();
    resetUi();
}

BigNode::~BigNode()
{
    delete ui;
}

void BigNode::setStatus(const QString &status)
{
    m_status = status;
    ui->status->setText(m_status);
}

void BigNode::setQueueNo(const QString &queueNo)
{
    m_queueNo = queueNo;
    ui->queueNo->setText(m_queueNo);
}

void BigNode::setDisplayedName(const QString &displayedName)
{
    m_displayedName = displayedName;
    ui->displayedName->setText(m_displayedName);
}

void BigNode::setService(const QString &service)
{
    m_service = service;
    ui->service->setText(m_service);
}

void BigNode::updateUi(NDHelper *dt)
{
    const QString &status = (dt->request()==CALLING) ?
                QString( "%1 %3 %2x" ).arg( dt->requestText() ).arg( dt->calledCount() ).arg
                ( ( dt->calledCount()==1 ) ? "/" : "-" ) : dt->requestText();

    ui->service->setText( dt->service() );
    ui->queueNo->setText( dt->queueNoText() );
    ui->displayedName->setText( dt->displayedName() );
    ui->status->setText( status );

    // stylesheet
    QString qssFilename = EXTRADIR + APPNAME + "_" + m_windowName + "_" + dt->requestText() + ".qss";
    QString styleSheet = "";
    if( dt->request()==REQUEST::CALLING )
        styleSheet = textFromFile(qssFilename);
    setStyleSheet(styleSheet);

}

void BigNode::resetUi()
{
    mkCONFIX;
    const QString txt1 = confx->string( KEY("txtWelcome1"), "");
    const QString txt2 = confx->string( KEY("txtWelcome2"), "");
    const QString txt3 = confx->string( KEY("txtWelcome3"), "");
    const QString txt4 = confx->string( KEY("txtWelcome4"), "");

    ui->service         ->setText( txt1 );
    ui->queueNo         ->setText( txt2 );
    ui->displayedName   ->setText( txt3 );
    ui->status          ->setText( txt4 );
}

void BigNode::on_pushButton_clicked()
{

}
