/*
 * main.cpp
 * Dedy Yasriady
*/

#include "mainwindow.h"
#include <Inc/Application>

int main(int argc, char *argv[])
{
    Application a(argc, argv);

    // global variable constructed here!
    m_config =new DSettings(CONFIGFILE);
    m_confix =new DSettings(CONFIXFILE);
    m_dB = new DB();

    MainWindow w;
    w.show();

    return a.exec();
}
