#include "network.h"
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>


//Network * Network::instance = 0;

        Network::Network()
            :QObject()
        {

            tcpServer = new QTcpServer(this);
            connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
            std::cout<<"Network was created.\n";
        }


//        void Network::getCommand()
//        {
//            QDataStream in(tcpSocket);

//            if (blockSize == 0) // только начинаме чтение данных
//            {
//                if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
//                    return;
//                in >> blockSize;    // считали размер блока данных
//            }

//            if (tcpSocket->bytesAvailable() < blockSize)
//                return; // ждем, пока данные прийдут полностью;
//            else blockSize = 0;

//            in >> keyWord;
//            if(keyWord!='I')    // tсли команда не "Сфотографировать"
//            {
//                in >> object >> direction >> degrees;
//            };
//            std::cout <<"\nWe have a new command! Here it is:\n ("<<keyWord<<" , "<<object<<" , "<<direction<<", "<<degrees<<")\n";

//        }
\

        void Network::listen()
        {
            tcpServer->listen(QHostAddress::LocalHost, 5100); // от 0 до 1000 идут системные порты
            std::cout<<"Network listen.\n";
        }

        void Network::onNewConnection()
        {
            std::cout<<"Here is a new connection!\n";
        }
// не менять*************************************
