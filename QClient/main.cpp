#include <Inc/Application>
#include "client.h"
#include "mainwindow.h"
#include "globals.h"
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    Application a(argc, argv);

    m_config = new DSettings(CONFIGFILE);
    m_confix = new DSettings(CONFIXFILE);

    Client w;
    //MainWindow w;

    w.show();
    return a.exec();
}
