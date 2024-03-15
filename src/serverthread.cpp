#include "../include/serverthread.h"

ServerThread::ServerThread(QObject *parent)
{
    if(parent){}//
}

void ServerThread::run()
{
    MyServer server;
    connect(&server,SIGNAL(newDataRecieved(QByteArray)),this,SIGNAL(newDataRecieved(QByteArray)));

    server.startServer();

    exec();
}
