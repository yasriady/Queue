#include "bignodebase.h"
#include "ui_bignodebase.h"

BigNodeBase::BigNodeBase(QWidget *parent) :
    DWidget(parent),
    ui(new Ui::BigNodeBase)
{
    ui->setupUi(this);
    updateUi( new NDHelper() );

    // clearn control
    ui->queueNo->setText("");
    ui->displayedName->setText("");
    ui->status->setText("");
    ui->service->setText("");

}

BigNodeBase::~BigNodeBase()
{
    delete ui;
}

void BigNodeBase::updateUi(NDHelper *dt)
{
    const QString &status = (dt->request()==CALLING) ?
                QString( "%1 %3 %2x" ).arg( dt->requestText() ).arg( dt->calledCount() ).arg
                ( ( dt->calledCount()==1 ) ? "/" : "-" ) : dt->requestText();

    ui->service->setText( dt->service() );
    ui->queueNo->setText( dt->queueNoText() );
    ui->displayedName->setText( dt->displayedName() );
    ui->status->setText( status );

    // stylesheet
    QString qssFilename = EXTRADIR + "qss" + SEP + APPNAME + "_" + m_windowName + "_" + dt->requestText() + ".qss";
    QString styleSheet = "";
    if( dt->request()==REQUEST::CALLING )
        styleSheet = textFromFile(qssFilename);
    setStyleSheet(styleSheet);

}
