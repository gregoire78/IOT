#include "mainwindow.h"
#include <QApplication>
#include "performances.h"
#include "flux.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    flux myFlux;
    int f;
    f = myFlux.fluxet();

    return a.exec();
}
