#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include<QDebug>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;
};

#endif // MYSERVER_H
