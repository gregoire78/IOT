#include <QCoreApplication>
#include "myserver.h"
#include "mycpu.h"
#include "mymemory.h"
#include <string>
#include <string.h>
#include <iostream>

#include "flux.h"

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    /*MyServer Server;
    MyMemory memory;
    MyCPU *myCpu;*/

    /*double v;
    double b;*/

    /*v = memory.getMemory();
    printf("La mémoire utilisée est de: %F\n\n", v);

    b = myCpu->cpuPcent();
    printf("Le Pcentage CPU instantanne est %g\n", b);
    myCpu->liste();*/

    flux myFlux;
    string e;
    string s;
    e = myFlux.fluxentrant();
    cout<< "flux entrant :"<< e << endl;

    s = myFlux.fluxsortant();
    cout<< "flux sortant :"<< s << endl;


    return a.exec();
}

