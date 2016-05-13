#include "flux.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <string>

#define NomFic "/proc/net/dev"

using namespace std;

// string::substr
 string flux::fluxentrant(){
     string en;

     ifstream fichier("/proc/net/dev");
     if(fichier){
         string eth0, lo, ppp0;
         getline(fichier, eth0);
         getline(fichier, lo);
         getline(fichier,ppp0);
         cout << "eth0 : "<< eth0 <<endl;
         cout << "lo : "<< lo << endl;
         cout << "pp0 : "<< ppp0 <<endl;
         fichier.close();
         en = ppp0.substr(7,9);

         return en;
     }

     else
         cerr << "Impossible d'ouvrir le fichier" << endl;
     return 0;
 }
  string flux::fluxsortant(){
      ifstream fichier("/proc/net/dev");
      string sort;

      if(fichier){
          string eth0, lo, ppp0;
          getline(fichier, eth0);
          getline(fichier, lo);
          getline(fichier,ppp0);
          cout << "eth0 : "<< eth0 <<endl;
          cout << "lo : "<< lo << endl;
          cout << "pp0 : "<< ppp0 <<endl;
          fichier.close();
          sort = ppp0.substr(66,8);

          return sort;
      }

      else
          cerr << "Impossible d'ouvrir le fichier" << endl;
      return 0;
  }

flux::flux()
{

}
