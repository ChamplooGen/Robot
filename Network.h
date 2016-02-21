#ifndef NETWORK_H
#define NETWORK_H

#include <QTcpServer>
#include <QTcpSocket>

class Network: public QObject
{
    Q_OBJECT

    private:

        QTcpServer *tcpServer;
        QTcpSocket *tcpSocket;


        quint16 blockSize;
    // элементы пустой команды
        char keyWord;
        char object;
        char direction;
        quint16 degrees;

    public:

        Network();
        void listen();

    private slots:
        void onNewConnection();

};

#endif // NETWORK_H
