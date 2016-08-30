#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :
      DMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QString connectionName = "db_" + QApplication::applicationName();
    mkCONFIG;
    m_db = new DB( connectionName, DRIVER_, DBNAME_, DBSRV_, DBUSER_, DBPWD_ );
    m_print = new Print(ui->ticket);

    ui->ticket->setDB(m_db);
    m_busy = false;

    SB->setConnPixmap( m_db->isConnected() );
    //const QString &text = ( (DRIVER_=="QSQLITE") ? "" : DBSRV_ );
    SB->setDbBackend("" + DRIVER_ + ( (DRIVER_=="QSQLITE") ? "" : ("@"+DBSRV_) ) );

    ui->dockWidget_2->hide();

}

MainWindow::~MainWindow()
{
    //delete m_movie;
    delete m_print;
    delete m_db;
    delete ui;
}

void MainWindow::setButton(const bool &enable)
{
    QList<QPushButton*>::iterator i;
    for( i = m_btnList.begin(); i != m_btnList.end(); i++ )
    {
        (*i)->setEnabled(enable);
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    (void)event;

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
        m_btnList.push_back(btn);
    }
    ui->frame->setLayout(layout);

    //ui->frame_Test->hide();
    //ui->ticket->hide();

    DMainWindow::showEvent(event);
}

void MainWindow::slotMakeTicket()
{
    if( m_busy ) return;
    m_busy = true;

    // http://stackoverflow.com/questions/34668541/qt-custom-qpushbutton-clicked-signal

    m_button = qobject_cast<QPushButton*>(sender());
    //QPushButton *btn = (QPushButton*) sender();
    const QString &groupCode = m_button->property("groupCode").toString();
    const QString &ticket = ui->ticket->makeTicket(groupCode);
    QTimer *timer = new QTimer(this);
    timer->setProperty("ticket", QVariant(ticket));
    connect( timer, SIGNAL(timeout()), this, SLOT(slotMyTimer()));
    timer->start(100);
    //QTimer::singleShot(100, this, SLOT(slotMyTimer()));
    //setButton(false);

}

void MainWindow::slotMyTimer()
{
    QTimer *timer = qobject_cast<QTimer*>(sender());
    const QString &ticket = timer->property("ticket").toString();
    timer->deleteLater();
    //Print *prt = new Print(ui->ticket);
    //prt->doPrint(*ui->ticket, ticket);
    m_print->doPrint(*ui->ticket, ticket);
    //setButton(true);
    m_busy = false;
}

//void MainWindow::TestingPrint1()
//{
//    QPrinter printer(QPrinter::HighResolution);
//    printer.setOutputFileName("print.ps");
//    QPainter painter;
//    painter.begin(&printer);
//    for( int page=0; page < numOfPages; page++ )
//    {
//        // use painter to draw on the page
//        if( page != lastPage )
//            printer.newPage();
//    }
//    painter.end();


//    // create painter for drawing print page
//    QPrinter printer(QPrinter::HighResolution);
//    QPainter painter(&printer);
//    int     w = printer.pageRect().width();
//    int     h = printer.pageRect().height();
//    QRect   page(0, 0, w, h);

//    // create a font approriate to page size
//    QFont   font = painter.font();
//    font.setPixelSize( (w+h)/100 );
//    painter.setFont(font);

//    painter.begin(&printer);

//    // draw label in the corner of the page
//    //painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, "QSimulate" );

//    painter.end();
//}

//void MainWindow::TestingPrint2()
//{
//    const QString filename = "CppQPrinterExample1.pdf";
//    // Set up a QPrinter
//    QPrinter printer;
//    printer.setOutputFormat( QPrinter::PdfFormat );
//    printer.setOrientation( QPrinter::Portrait );
//    printer.setPaperSize( QPrinter::A4 );
//    printer.setFullPage( false );
//    printer.setOutputFileName(filename);


//    //Grab the window
//    const QImage image = QPixmap::grabWindow(this->winId()).toImage();

//    //Draw the image to painter to printer
//    QPainter painter;
//    painter.begin(&printer);
//    painter.drawImage(0,0,image);
//    painter.end();

//Assume the PDF is created
//assert(QFile::exists(filename));
//}

void MainWindow::on_pushButton_clicked()
{
    //SB->setConnIndicator( true );

    //m_movie = new QMovie("/home/dedy/Videos/Movie/Belajar &#39;Iqro - YouTube.MP4");
    //ui->movie->setMovie(m_movie);
    //m_movie->start();

    m_mediaPlayer = new QMediaPlayer(this);
    m_mediaPlaylist = new QMediaPlaylist(m_mediaPlayer);

    m_mediaPlaylist->addMedia( QUrl::fromLocalFile("file:///home/dedy/Videos/Movie/English/Belajar_Mengenal_Organ_Tubuh.mp4") );
    m_mediaPlaylist->addMedia( QUrl::fromLocalFile("file:///mnt/SDB4/Games/aoe/avi/Introx.avi") );
    m_mediaPlaylist->addMedia( QUrl::fromLocalFile("file://home/dedy/Videos/Qt/declarative-adv-tutorial4.gif") );

    m_mediaPlayer->setVideoOutput( ui->videoWidget );
    ui->videoWidget->show();
    m_mediaPlaylist->setCurrentIndex(2);
    m_mediaPlayer->play();


}

