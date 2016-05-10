#include <QCoreApplication>
#include "myserver.h"
#include "mycpu.h"
#include "mymemory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer Server;
    MyMemory memory;
    MyCPU *myCpu;

    double v;
    //double b;

    /*v = memory.getMemory();
    printf("La mémoire utilisée est de: %F\n\n", v);*/

    /*b = myCpu->cpuPcent();
    printf("Le Pcentage CPU instantanne est %g\n", b);*/
    //myCpu->liste();
    return a.exec();
}
