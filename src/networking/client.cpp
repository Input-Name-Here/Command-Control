
#include <iostream>
#include <stdio.h>
#include <iostream>
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
        struct argument arg;
        arg.data = "hello";
        arg.type = "arg";
        conmsg.arguments = {arg};
        conmsg.flags = 0x0000;
        conmsg.debug();
        std::vector<unsigned char> msgoutput = conmsg.encode();
        std::string stroutput = std::string(msgoutput.begin(),msgoutput.end());
        std::cout << stroutput << std::endl;
        qInfo("Sucessfully connected to server.");
        socket_thread = std::thread(thread_listen, this);
        qInfo("Sucessfully connected to server.");
        //QByteArray bytemsg;
        QByteArray bytemsg = QByteArray(reinterpret_cast<const char*>(msgoutput.data()), msgoutput.size());
        socket->write(bytemsg);

    }

    void Client::thread_listen(Client *cl)
    {
        while(cl->socket->bytesAvailable()){
            // Do stuff
        }

    }

}

