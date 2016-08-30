#include <Application>
#include "client.h"
#include "mainwindow.h"

#include <QStyleFactory>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    Client w;
    //MainWindow w;

    w.show();
    return a.exec();
}
