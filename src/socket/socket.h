//#ifndef SOCKET_H
#define SOCKET_H
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using std::string;
//using std::thread;

class Socket {
    private:
        struct sockaddr_in ServerIp;
        int Port;
        int IpAddr;
        int Sock;
        char buffer[1024];
        //struct ServerIp;
    public:
        Socket(int port, string addr);
        void Connect();
        void Send(string message);
        string Recv();
};

//#endif // SOCKET_H
