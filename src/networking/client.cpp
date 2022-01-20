
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <thread>
#include "networking/client.h"
#include <exception>
#include "networking/protocol.h"

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

    void Client::Connect(QString server_ip, unsigned int port)
    {
        socket->connectToHost(server_ip, port);
        try{
            if(!socket->waitForConnected(5000)){
                qWarning("Unable to connect to server %s", server_ip.toStdString().c_str());
                return;
            }
        }catch (std::exception& ex){
            qWarning(ex.what());
        }

        message conmsg;
        conmsg.arguments = {};
        conmsg.type = 0x00;
        conmsg.flags = 0x0000;
        std::cout << conmsg.encode() << std::endl;
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

