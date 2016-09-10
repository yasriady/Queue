//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QPrinter>
#include <QPainter>
#include <QWidget>
#include <QImage>
#include <QFile>
#include <cassert>
#include <QScreen>
#include <QTextBrowser>
#include <QDir>
#include "config.h"
#include <Config>

// http://www.richelbilderbeek.nl/CppQPrinterExample1.htm

class Print : public QPrinter
{
public:
    Print(QWidget *parent);
    ~Print();

private:
    QString m_filename;
    QPainter m_painter;
    QWidget *m_parent;
    QString m_ticketDir;

public:
//    void testPrint1();
//    void testPrint2( const QTextEdit *textEdit);
//    void testPrint3( const QWidget *w);
    void doPrint(const QWidget &w, const QString &ticket);

};

#endif // PRINT_H
