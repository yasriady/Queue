#include "mainwindow.h"
#include <Inc/Application>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
