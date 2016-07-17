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
        static QChar type;
        static QChar direction;
        //static quint16 angle;

        bool commandIsReady;    // индикатор готовности команды

    public:
        Network();
        void listen();
        void getCommand();
        QTcpServer * GetTcpServer() const {return tcpServer;}
        QTcpSocket * GetTcpSocket() const {return tcpSocket;}

        static QChar GetKeyWord() {return keyWord;}
        static QChar GetType() {return type;}
        static QChar GetDirection() {return direction;}
        //static quint16 GetAngle() {return angle;}


        bool IsCommandReady() const { return commandIsReady;}

    private slots:
        void onNewConnection();
        void recievingCommand();
};

#endif // NETWORK_H

