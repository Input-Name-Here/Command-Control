
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <thread>
#include "networking/client.h"

namespace CommandControl::Networking {

    Client::Client(QObject *parent) :
        QObject(parent)
    {
        socket = new QTcpSocket(this);
    }

    Client::~Client()
    {
        socket_thread.join();
    }

    void Client::Connect(QString server_ip, uint8_t port)
    {
        socket->connectToHost(server_ip, port);

        if(!socket->waitForConnected(5000)){
            qWarning("Unable to connect to server %s", server_ip.toStdString().c_str());
            return;
        }

        qInfo("Sucessfully connected to server.");
        socket_thread = std::thread(thread_listen, this);


    }

    void Client::thread_listen(Client *cl)
    {
        while(cl->socket->bytesAvailable()){
            // Do stuff
        }

    }

}

