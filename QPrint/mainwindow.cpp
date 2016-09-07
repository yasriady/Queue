#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    DMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ticket = ui->ticket;
    mkDB;
    m_ticket->setDB(m_db);
    m_sound = new DCallerSound(this);

    const QString &sql = " SELECT * FROM GroupList ";
    QJsonObject records = m_db->getRecord3(sql);

    QVBoxLayout *layout = new QVBoxLayout(ui->frame_2);
    layout->setMargin(20);
    layout->setSpacing(20);
    for(int i=0; i<records.size(); i++ )
    {
        QJsonValue rcd1 = records[ QString::number(i) ];
        QJsonObject rcd2 = rcd1.toObject();

        const QString groupCode = rcd2["group_code"].toString();
        const QString &lbl = rcd2["service"].toString() + " (" + groupCode + ")";

        DPushButton *btn = new DPushButton( lbl, ui->frame_2 );
        btn->setProperty( "groupCode", groupCode );
        btn->setObjectName( lbl );

        QSizePolicy p = btn->sizePolicy();
        p.setVerticalPolicy(QSizePolicy::Preferred);
        p.setVerticalStretch(1);
        btn->setSizePolicy(p );
        layout->setSpacing(10);

        connect( btn, SIGNAL(clicked(bool)), this, SLOT(slotMakeTicket()) );
        layout->addWidget(btn, 1);
    }
    ui->frame_2->setLayout(layout);
    // update status bar
    mkCONFIG;
    SB->setConnText( m_db->isConnected() );
    SB->setConnPixmap( m_db->isConnected() );
    SB->setDbBackend(DRIVER_+ ":" + DBSRV_);

    mkCONFIX;
    QString picFilename = confx->string( KEY("mainPic")  );
    ui->mainPic->setPixmapFile(picFilename);
}

MainWindow::~MainWindow()
{
    delete m_sound;
    delete m_db;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_ticket->showLastTicket();
}

void MainWindow::slotMakeTicket()
{
    QStringList strList;
    strList.insert(0, "Ding-dong_C");
    m_sound->call(strList);

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    const QString groupCode = button->property("groupCode").toString();
    m_ticket->createNew(groupCode);
}

void MainWindow::customInit()
{
    m_windowName = "MainWindow";
    setWindowTitle("QPrint");
}
