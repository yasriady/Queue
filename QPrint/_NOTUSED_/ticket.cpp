#include "ticket.h"
#include "ui_ticket.h"

Ticket::Ticket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
    m_dt = new TicketData();
}

Ticket::~Ticket()
{
    delete m_dt;
    delete ui;
}

void Ticket::makeHeader()
{
    mkCONFIG;

    const QString &logoFile = EXTERADIR +  conf->string("TICKET/Logo") ;
    ui->logo->setPixmap(QPixmap(logoFile));
    ui->logo->setFixedSize(QSize(100, 130));
    ui->logo->setScaledContents(true);

    const QString &header1 = conf->string("TICKET/Header1");
    const QString &header2 = conf->string("TICKET/Header2");
    const QString &header3 = conf->string("TICKET/Header3");
    const QString &header4 = conf->string("TICKET/Header4");
    const QString &header5 = conf->string("TICKET/Header5");

    ui->header1->setText( header1 );    if( header1.isEmpty() ) ui->header1->hide();
    ui->header2->setText( header2 );    if( header2.isEmpty() ) ui->header2->hide();
    ui->header3->setText( header3 );    if( header3.isEmpty() ) ui->header3->hide();
    ui->header4->setText( header4 );    if( header4.isEmpty() ) ui->header4->hide();
    ui->header5->setText( header5 );    if( header5.isEmpty() ) ui->header5->hide();

}

void Ticket::showEvent(QShowEvent *event)
{
    ui->w_displayedName->hide();
    ui->widget_PELAYANAN->hide();

    makeHeader();
    showLastTicket();

    QWidget::showEvent(event);
}

void Ticket::setDB(DB *db)
{
    m_db = db;
}

void Ticket::showLastTicket()
{
//    QJsonValue rcd = m_db->getLastPrintedQueue();
//    QString groupCode = "X";
//    int queueNo = 0;
//    if( rcd.size() > 0 ) {
//        groupCode = ( rcd["group_code"].toVariant() ).toString();
//        queueNo = ( rcd["queue_no"].toVariant() ).toInt();
//    }

//    updateTicket(groupCode, queueNo);
}

QString Ticket::makeTicket(const QString &groupCode)
{
    // make queue
    //QString groupCode = button->property("groupCode").toString();
    uint8_t queueNo = m_db->getMaxQueueNo(groupCode) + 1;

    // update to database
    QString sql = QString( " INSERT INTO PrintedQueue(group_code, queue_no, status, called_count, processed_by) " );
    sql += QString( " VALUES( '%1', %2, 0, 0, NULL ) " ).arg(groupCode).arg(queueNo);
    m_db->updateRecord(sql);
    updateTicket(groupCode, queueNo);

    return m_ticket;
}

void Ticket::updateTicket(const QString &groupCode, const int &queueNo)
{
    // get just created ticket
    //sql = QString( " SELECT * FROM v_PrintedQueue WHERE group_code='%1' AND queue_no=%2 " ).arg(groupCode).arg(queueNo);
    QJsonObject rcd = m_db->getPrintedQueue(groupCode, queueNo);

    m_dateTime = QDateTime::currentDateTime();
    m_displayedName = "m_displayedName";
    m_groupAssignment = "m_groupAssignment";
    m_ticket = "m_ticket";
    m_numOfWaiting = 0;

    if( queueNo > 0 ) {
        m_dateTime = ( rcd["ts"].toVariant() ).toDateTime();
        m_displayedName = rcd["processed_by"].toString();
        m_groupAssignment = rcd["service"].toString();
        m_ticket = QString( "%1-%2" ).arg(groupCode).arg(queueNo, 3, 10, QChar('0'));
        m_numOfWaiting = m_db->getNumOfWaiting(groupCode);
    }

    ui->w_dateTime->setTextFromDateTime( m_dateTime );
    ui->w_displayedName->setText( m_displayedName );
    ui->w_groupAssignment->setText( m_groupAssignment );
    ui->w_ticket->setText( m_ticket );
    ui->w_numOfWaiting->setText( QString("Sisa antrian: %1 orang").arg(m_numOfWaiting) );

}











