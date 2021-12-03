#ifndef SOCKET_H
#define SOCKET_H

class Socket {
    public:
        int Port;
        int IpAddr;
        int Sock;
        Socket(int port, int addr);
        void Connect();
};

#endif // SOCKET_H
