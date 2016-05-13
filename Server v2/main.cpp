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
        string e;
        string s;
        e = myFlux.fluxentrant();
        cout<< "flux entrant :"<< e << endl;

        s = myFlux.fluxsortant();
        cout<< "flux sortant :"<< s << endl;
    return a.exec();
}
