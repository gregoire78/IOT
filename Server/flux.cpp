#include "flux.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

 int flux::fluxet(){
     ifstream fichier("/proc/net/dev");
     if(fichier){
         string eth0, lo, ppp0;
         getline(fichier, eth0);
         getline(fichier, lo);
         getline(fichier,ppp0);
         cout << eth0 <<endl;
         cout << lo << endl;
         cout << ppp0 <<endl;



         fichier.close();
     }

     else
         cerr << "Impossible d'ouvrir le fichier" << endl;
     return 0;
 }
flux::flux()
{

}
