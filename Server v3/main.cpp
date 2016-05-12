#include "mainwindow.h"
#include <QApplication>
#include "performances.h"
#include "flux.h"
#include "choice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    performances perf;
    //perf.show();
    Choice choice;
   //choice.show();
    /*flux myFlux;
    int f;
    f = myFlux.fluxet();*/

    return a.exec();
}
