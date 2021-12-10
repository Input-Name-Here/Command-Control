
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "src/socket/socket.h"
#include <string.h>
#include <string>
#include <unistd.h>
#include <thread>


Socket::Socket(QObject *parent) :
    QObject(parent)
{
}

void Socket::doConnect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("google.com", 80);

    if(socket->waitForConnected(5000))
    {
        qDebug() << "Connected!";
        // send
        socket->write("Hello server\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        // get the data
        qDebug() << socket->readAll();
        // close the connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }
}

