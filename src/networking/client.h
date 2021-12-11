#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <thread>

namespace CommandControl::Networking {

    class Client : public QObject
    {
        Q_OBJECT
    public:
        explicit Client(QObject *parent = 0);
        ~Client();

        void Connect(QString server_ip, uint8_t port);
    private:
        static void thread_listen(Client* cl);
    signals:

    public slots:

    private:
        QTcpSocket* socket;
        std::thread socket_thread;
        QString address;
        uint8_t port;

    };

}

#endif // SOCKET_H
