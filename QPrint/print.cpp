#include "print.h"

Print::Print(QWidget *parent)
{
    m_parent = parent;

    setResolution( QPrinter::PrinterResolution);
    setOutputFormat( PdfFormat );
    setOrientation( Portrait );
    setPaperSize( QPrinter::A7 );
    setFullPage( true );

    // create ticket dir (Today)
    QString today = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    m_ticketDir = QApplication::applicationDirPath() + QDir::separator() + "Ticket" + QDir::separator() + today + QDir::separator();
    QDir *dir = new QDir(m_ticketDir);
    dir->mkdir(m_ticketDir);
}

Print::~Print()
{
}

//void Print::testPrint1()
//{
//    // Grab image
//    const QImage image = QPixmap::grabWindow(m_parent->winId()).toImage();

//    // Draw image to painter to printer
//    m_painter.begin(this);
//    m_painter.drawImage( 0, 0, image );
//    m_painter.end();

//    //Assume the PDF is created
//    assert(QFile::exists(m_filename));
//}

//void Print::testPrint2(const QTextEdit *textEdit)
//{
//    //textEdit->print(this);
//    const QImage image = QPixmap::grabWindow( textEdit->winId() ).toImage();
//    // Draw image to painter to printer
//    m_painter.begin(this);
//    //m_painter.drawImage( 0, 0, image );
//    m_painter.drawImage( pageRect(), image, textEdit->rect() );
//    m_painter.end();
//}

//void Print::testPrint3(const QWidget *w)
//{
//    const QImage image = QPixmap::grabWindow( w->winId() ).toImage();
//    // Draw image to painter to printer
//    m_painter.begin(this);
//    m_painter.drawImage( pageRect(), image, w->rect() );
//    m_painter.end();
//}


void Print::doPrint(const QWidget &w, const QString &ticket)
{
//    m_painter.begin(this);
//    //m_painter.drawText( pageRect(), Qt::AlignTop|Qt::AlignHCenter, "Azzam" );
//    const QImage image = QPixmap::grabWindow( m_template->winId()).toImage();
//    // Draw image to painter to printer
//    m_painter.begin(this);
//    m_painter.drawImage( 0, 0, image );
//    m_painter.end();
//    m_painter.end();

    m_filename = m_ticketDir + ticket + ".pdf";
    setOutputFileName( m_filename );

    QScreen *screen = QGuiApplication::primaryScreen();

    const QImage &image = screen->grabWindow(w.winId()).toImage();

    //const QImage &image = QPixmap::grabWindow(w.winId()).toImage();
    m_painter.begin(this);
    m_painter.drawImage( pageRect(), image, w.rect(), Qt::MonoOnly );
    m_painter.end();
    //Assume the PDF is created
    assert(QFile::exists(m_filename));
}
