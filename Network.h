#ifndef NETWORK_H
#define NETWORK_H

#include <QDialog>

class QLabel;
class QPushButton;
class QTcpServer;
class QTcpSocket;
class QNetworkSession;

class Network: public QDialog
{
    Q_OBJECT

    private:
        static Network * instance;
        Network(QWidget *parent = 0);

        QLabel *statusLabel;
        QPushButton *quitButton;
        QTcpServer *tcpServer;
        QTcpSocket *tcpSocket;
        QNetworkSession *networkSession;

        quint16 blockSize;
    // элементы пустой команды
        char keyWord;
        char object;
        char direction;
        quint16 degrees;

    public:
        ~Network();
        static Network * GetInstance();
        static void DestroyInstance();

//        virtual void Listen();	// слушать эфир
//        virtual void Connect();
//        virtual void Disconnect();
//        virtual void Send();	// отправить данные
//        virtual void Get();		// принять данные

    private slots:
        void sessionOpened();
        void sendMessage();
        void getCommand();

};

#endif // NETWORK_H
