#include "nodebase.h"
#include "ui_nodebase.h"

NodeBase::NodeBase(QWidget *parent) :
    DWidget(parent),
    ui(new Ui::NodeBase)
{
    ui->setupUi(this);
}

NodeBase::~NodeBase()
{
    delete ui;
}

void NodeBase::updateUi(NDHelper &dt)
{
    m_dt.setQueueNo( dt.queueNo() );
    m_dt.setRequest(dt.request());
    m_dt.setRequestText( dt.requestText() );

    ui->displayedName->setText( m_dt.displayedName() );
    ui->queueNo->setText( m_dt.queueNoText() );

    // stylesheet
    QString qssFilename = EXTRADIR + "qss" + SEP  + APPNAME + "_" + m_windowName + "_" + m_dt.requestText() + ".qss";
    QString styleSheet = "";
    if( m_dt.request()==REQUEST::CALLING )
        styleSheet = textFromFile(qssFilename);
    setStyleSheet(styleSheet);

}

const NDHelper &NodeBase::dt() const
{
    return m_dt;
}

