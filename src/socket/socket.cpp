#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "src/socket/socket.h"
#include <string.h>
#include <unistd.h>

//#import std


Socket::Socket(int port, int addr){
    printf("\nInitialisation\n");
    //IpAddr = inet_addr("127.0.0.1");
    //Port = htons(5123);
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
}

void Socket::Connect(){
    struct sockaddr_in ServerIp;
    ServerIp.sin_family= AF_INET;
    ServerIp.sin_port=htons(5123);//htons(5123);
    ServerIp.sin_addr.s_addr=inet_addr("127.0.0.1");
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

std::string Socket::Recv(){
    ssize_t len = recv ( Sock , buffer , 1024,0 );
    //std::string buffermsg(buffer,buffer+len);
    //std::string message = buffermsg.substr(0,len);
    return "hi";
}
