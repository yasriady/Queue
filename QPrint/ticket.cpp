#include "ticket.h"
#include "ui_ticket.h"

Ticket::Ticket(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
    makeTemplate();
    QDir dir; dir.mkdir(TICKETDIR);
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::setDB(DB *db)
{
    m_db = db;
}

void Ticket::showLastTicket()
{
    m_rcd = m_db->getLastPrintedQueue();
    updateTicket();
}

void Ticket::createNew(const QString &groupCode)
{
    int nextQueueNo = m_db->getMaxQueueNo(groupCode) + 1;
    const QString &sql = QString( " INSERT INTO PrintedQueue(group_code, queue_no) VALUES('%1', %2); " ).arg(groupCode).arg(nextQueueNo);
    m_db->updateRecord( sql );
    showLastTicket();
    ui->printPreview->print();
}

void Ticket::makeTemplate()
{
    mkCONFIX;
    //QString fileName = EXTRADIR + confg->string("TICKET/Template");
    QString ticketTemplate = confx->string( KEY("ticketTemplate"), "TicketTemplate.html" );
    ticketTemplate = EXTRADIR + ticketTemplate;
    QFile file(ticketTemplate);
    file.open( QIODevice::ReadOnly );
    m_template = file.readAll();
}

void Ticket::updateTicket()
{

    const QString &groupCode = m_rcd["group_code"].toString();
    const QString &numOfWaiting = QString::number( m_db->getNumOfWaiting( groupCode ) );
    const int &queueNo = m_rcd["queue_no"].toString().toInt(); // Ddy: QJsonObject cannot direct convert to String, toStr() was now worked?

    const QString &_date        = m_rcd["date"].toString();
    const QString &_time        = m_rcd["time"].toString();
    const QString &_node        = "";
    const QString &_service     = m_rcd["service"].toString();
    const QString &_ticket      = TICKET(groupCode, queueNo);
    const QString &_numOfWaiting= numOfWaiting;

    QString templt = m_template;
    templt = templt.replace("%date", _date, Qt::CaseSensitive);
    templt = templt.replace("%time", _time, Qt::CaseSensitive);
    templt = templt.replace("%node", _node, Qt::CaseSensitive);
    templt = templt.replace("%service", _service, Qt::CaseSensitive);
    templt = templt.replace("%ticket", _ticket, Qt::CaseSensitive);
    templt = templt.replace("%numOfWaiting", _numOfWaiting, Qt::CaseSensitive);

    ui->printPreview->updatePreview( templt, TICKETDIR + TICKETFILE);
}

void Ticket::showEvent(QShowEvent */*event*/)
{
    showLastTicket();
}
