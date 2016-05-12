#include <iostream>
#include <string>
#include <unistd.h>

#include <QString>
#include <QLocale>
//#include <QInputDialog>

#include "myserver.h"
#include "mymemory.h"
#include "mycpu.h"

using namespace std;

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,1234)){
        qDebug() << "Server could not start!";
    }
    else{
        qDebug() << "Server started";
    }
}


void MyServer::newConnection()
{
    MyMemory memory;
    MyCPU myCpu;

    QString message;
    QString cpuMess;

    double memoryMess = memory.getMemory();
    double cpuMessage = myCpu.cpuPcent();

    QTcpSocket *socket = server->nextPendingConnection();
    message = QString::number(memoryMess, 'f', 6);
    cpuMess = QString::number(cpuMessage, 'f', 6);

    /*Demander si le client veut écrire ou lire*/
    //socket->write("Hello Client, que veux-tu faire ? Lire ou Ecrire ?\n");
    socket->write("Hello client, voici les données CPU et Mémoire du PC: \r\n");
    //Lecture
    socket->write("CPU: " + cpuMess.toLatin1() + "\r\n");
    socket->write("Memoire: " + message.toLatin1() + "\r\n");
    socket->flush();

    socket->waitForBytesWritten(5000);

    socket->close();

    //Ecriture

}
