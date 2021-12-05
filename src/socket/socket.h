#ifndef SOCKET_H
#define SOCKET_H
#include <string.h>
#include <iostream>
#include <stdio.h>
class Socket {
    public:
        int Port;
        int IpAddr;
        int Sock;
        char buffer[1024];
        //struct ServerIp;
        Socket(int port, int addr);
        void Connect();
        void Send(std::string message);
        std::string Recv();
};

#endif // SOCKET_H
