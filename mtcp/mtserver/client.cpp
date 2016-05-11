#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "tcpconnector.h"
#include <iostream>
#include <unistd.h>
#include <ctime>

#define NomFic "/proc/stat"
#define NomFic2 "/proc/cpuinfo"

using namespace std;


#define LBUF 500
string cpuIng(void)
{
FILE * fp;
char nom [100];
char nom2[200];
char reste[200];
char buf[LBUF], *b;
int n, s1,s2;
char m1 [] = "name";
char m2 [] = "MHz";
char m3 [] = "cores";
char m4 [] = "processor";
string message;
   if ((fp = fopen(NomFic2, "r")) == NULL) return message;
   while (fgets(buf, LBUF, fp) != NULL) {
      n=strlen(buf);
      buf[n-1]='\0';
      s1 = sscanf(buf,"%s %s :", nom, nom2);
      b = strchr(buf,':');
      if (b==NULL) continue;
      s2 = sscanf(b+1," %s", reste);
      //printf("Lu : <%s> s1=%d s2=%d nom=%s reste=%s\n", buf, s1, s2, nom, b+1);
      if (strcmp(m1, nom2) == 0)
      {
        //printf("%s\n", b+1 );
        message += b+1;
        message += " - ";
      }
      if (strcmp(m2,nom2) == 0)
      {
        //printf("%s\n", b+1);
        message += b+1;
        message += " MHz - ";
      }
      if (strcmp(m3,nom2) == 0)
      {
        //printf("%s\n", b+1);
        message += b+1;
        message += " cores ---";
      }
      //if (strcmp(m4,nom) == 0)
      //{
      //  //printf("%s\n", b+1);
      //  message += "( ";
      //  message += b+1;
      //  message += " : processor )";
      //}
   }
   fclose(fp);

   return message;
}


string timy ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S:%u",timeinfo);
  std::string str(buffer);

  return str;
}


/* fonction qui accede a l'interface et qui calcule le pourcentage */
double cpuPcent(void)
{
FILE * fp;
char nom [10];
long v1, v2, v3, v4;
long vp1, vp2, vp3, vp4;
long d1, d2, d3, d4;
double res=0.;
   if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
   fscanf(fp,"%s %ld %ld %ld %ld", nom, &v1, &v2, &v3, &v4);
   //printf("%s %ld %ld %ld %ld\n",nom,v1,v2,v3,v4);
   sleep(1);
   //usleep(500000);
   rewind(fp);
   if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
   fscanf(fp,"%s %ld %ld %ld %ld", nom, &vp1, &vp2, &vp3, &vp4);
   //printf("%s %ld %ld %ld %ld\n",nom,vp1,vp2,vp3,vp4);
   d1 = vp1 - v1;
   d2 = vp2 - v2;
   d3 = vp3 - v3;
   d4 = vp4 - v4;
   res = (double)((d1+d2+d3) * 100L) / (double)(d1+d2+d3+d4);
   return res;
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    int len;
    string message;
    char line[256];
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(argv[2], atoi(argv[1]));


    //if (stream) {
    //    message = "{\"info\":\"" + cpuIng() + "\"}";
    //    stream->send(message.c_str(), message.size());
    //    printf("sent - %s\n", message.c_str());
    //    len = stream->receive(line, sizeof(line));
    //    line[len] = NULL;
    //    printf("received - %s\n", line);
    //    //delete stream;
    //}

    //stream = connector->connect(argv[2], atoi(argv[1]));
    while (stream) {
      message = "{\"cpu\":\"" + to_string(cpuPcent()) + "\", \"time\":\"" + timy() + "\", \"info\":\"" + cpuIng() + "\"}";
      stream->send(message.c_str(), message.size());
      printf("sent - %s\n", message.c_str());
      len = stream->receive(line, sizeof(line));
      line[len] = NULL;
      printf("received - %s\n", line);
      //delete stream;
    }
    
    exit(0);
}
