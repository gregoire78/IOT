#include "mymemory.h"
#include <unistd.h>
#include <iostream>
#include <stdio.h>

using namespace std;

#define NomFic "/proc/meminfo"

MyMemory::MyMemory()
{

}

double MyMemory::getMemory()
{
    FILE * fp;

        char nom[10];
        char c[10];
        long v1, v2, v3, v4;
        long memRes;
        double res=0.;

        if((fp = fopen(NomFic, "r")) == NULL)   cout << "Erreur dans la lecture du fichier!" << endl;

        cout << "Voici l'utilisation de la mémoire: " << endl;
        //MemTotal
        fscanf(fp, "%s %ld %s", nom, &v1, c);
        printf("%s %ld %s\n", nom, v1, c);

        //MemFree
        for(int i=0; i<1; ++i){
            fscanf(fp, "%s %ld %s", nom, &v2, c);
            printf("%s %ld %s\n", nom, v2, c);
        }

        //Buffer
        for(int i=3; i<=4; ++i){
            fscanf(fp, "%s %ld %s", nom, &v3, c);
        }
        printf("%s %ld %s\n", nom, v3, c);

        //Cache
        for(int i=3; i<4; ++i){
            fscanf(fp, "%s %ld %s", nom, &v4, c);
        }
        printf("%s %ld %s\n", nom, v4, c);
        /*sleep(5);
        rewind(fp);*/

        //Mémoire utilisée
        memRes = v2+v3+v4;
        res = (double)(v1-memRes);

        return res;
}
