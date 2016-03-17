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

        static QChar keyWord;
        static QChar object;
        static QChar direction;
        static quint16 angle;

    public:
        Network();
        void listen();
        void getCommand() {return recievingCommand();}
        QTcpServer * GetTcpServer() const {return tcpServer;}
        QTcpSocket * GetTcpSocket() const {return tcpSocket;}

        static QChar GetKeyWord() {return keyWord;}
        static QChar GetObject() {return object;}
        static QChar GetDirection() {return direction;}
        static quint16 GetAngle() {return angle;}

    private slots:
        void onNewConnection();
        void recievingCommand();
};

#endif // NETWORK_H

