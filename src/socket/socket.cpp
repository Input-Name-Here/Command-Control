#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "src/socket/socket.h"
//#import std


Socket::Socket(int port, int addr){
    printf("\nInitialisation\n");
    IpAddr = addr;
    Port = port;
    if ((Sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }
    else{
        printf("\n Socket creation success \n");
    }
}

void Socket::Connect(){
    int a = connect(Sock, (struct sockaddr *)&IpAddr, sizeof(IpAddr));
    if (a<0)
    {
        printf("\nConnection Failed \n");
        printf(std::to_string(a).c_str());
        return;
    }else{
        printf("\nConnection Success \n");
    }

}
