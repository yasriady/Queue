#include "mainwindow.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    const QString connectionName = "db_" + QApplication::applicationName();
    mkCONFIG;
    m_db = new DB( connectionName, DRIVER_, DBNAME_, DBSRV_, DBUSER_, DBPWD_ );
    m_busy = false;

    const QString &sql = " SELECT * FROM GroupList ";
    QJsonObject records = m_db->getRecord3(sql);

    QVBoxLayout *layout = new QVBoxLayout(ui->frame);
    for(int i=0; i<records.size(); i++ )
    {
        QJsonValue rcd1 = records[ QString::number(i) ];
        QJsonObject rcd2 = rcd1.toObject();

        const QString &lbl = rcd2["service"].toString();

        QPushButton *btn = new QPushButton( lbl, ui->frame );
        btn->setProperty( "groupCode", rcd2["group_code"].toString() );
        btn->setObjectName( lbl );
        connect( btn, SIGNAL(clicked(bool)), this, SLOT(slotMakeTicket()) );
        layout->addWidget(btn, 1);
    }
    ui->frame->setLayout(layout);

    //ui->frame_Test->hide();
    //ui->ticket->hide();

    //ui->print->updatePreview("DATA");
    on_pushButton_clicked();

    SB->setConnPixmap( m_db->isConnected() );
    //const QString &text = ( (DRIVER_=="QSQLITE") ? "" : DBSRV_ );
    SB->setDbBackend("" + DRIVER_ + ( (DRIVER_=="QSQLITE") ? "" : ("@"+DBSRV_) ) );

}

MainWindow2::~MainWindow2()
{
    delete m_db;
    delete ui;
}

void MainWindow2::slotMakeTicket()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString groupCode = btn->property("groupCode").toString();
}


void MainWindow2::on_pushButton_clicked()
{
//    // QTextDocument
//    QString filePath = EXTRADIR + "TicketTemplate.html";
//    QFile file(filePath);
//    file.open( QIODevice::ReadOnly );
//    QTextStream in(&file);
//    QString html = in.readAll();
//    ui->print->updatePreview(html);

}

void MainWindow2::on_pushButton_2_clicked()
{

}
