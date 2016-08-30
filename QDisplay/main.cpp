#include <Application>

#include "MainWindow/mainwindow.h"
#include "MainWindow/mainwindowa.h"

#define MAINWINDOW              MainWindowA

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    MAINWINDOW w;
    w.show();

    return a.exec();
}
