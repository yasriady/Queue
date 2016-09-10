#include "mainwindow.h"
#include <Inc/Application>
#include "app_globals.h"

#define MAINWINDOW                  MainWindow

int main(int argc, char *argv[])
{
    Application a(argc, argv);

    // global variable constructed here!
    m_config =new DSettings(CONFIGFILE);
    m_confix =new DSettings(CONFIXFILE);
    m_dB = new DB();

    MAINWINDOW w;
    w.show();
    return a.exec();
}
