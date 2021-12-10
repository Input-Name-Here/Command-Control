#ifndef SOCKET_H
#define SOCKET_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <QObject>
using std::string;
//using std::thread;

class Socket : public QObject
{
    Q_OBJECT
    public:
        Socket(int port, string addr);
        void Connect();
        void Send(string message);
        string Recv();
    signals:
        void receiveMessage();
    private:
        struct sockaddr_in ServerIp;
        int Port;
        int IpAddr;
        int Sock;
        char buffer[1024];
        //struct ServerIp;
};

#endif // SOCKET_H
