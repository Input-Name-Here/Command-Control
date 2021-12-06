
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "src/socket/socket.h"
#include <string.h>
#include <string>
#include <unistd.h>
#include <thread>

using std::string;
using std::thread;

Socket::Socket(int port, string addr){
    printf("\nInitialisation\n");
    ServerIp.sin_family= AF_INET;
    ServerIp.sin_port=htons(port);//htons(5123);
    ServerIp.sin_addr.s_addr=inet_addr(addr.c_str());
    buffer[1024] = {0};
    Sock = socket(AF_INET, SOCK_STREAM, 0);
    if (Sock < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }
    else{
        printf("\n Socket creation success \n");
    }
    //thread RxLoopThread(RxLoop);
}

void Socket::Connect(){

    if(inet_pton(AF_INET, "127.0.0.1", &ServerIp.sin_addr) <= 0){
      puts("Invalid address");
      return;
    }
    int a = connect(Sock, (struct sockaddr *)&ServerIp, sizeof(ServerIp));
    if (a<0)
    {
        printf("\nConnection Failed \n");
        puts(std::to_string(a).c_str());
        puts(std::to_string(ServerIp.sin_addr.s_addr).c_str());
        puts(std::to_string(ServerIp.sin_port).c_str());
        return;
    }else{
        printf("\nConnection Success \n");
    }

}


void Socket::Send(std::string message){

    //send ( Sock , message , strlen(message.c_str()));
    send ( Sock , buffer , strlen(message.c_str()),0);

}

string Socket::Recv(){
    ssize_t len = recv ( Sock , buffer , 1024,0 );
    std::string buffermsg(buffer,buffer+len);
    std::string message = buffermsg.substr(0,len);
    return message;
}
