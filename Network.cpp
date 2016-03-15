#include "Network.h"
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

    QChar Network::keyWord = '0';
    QChar Network::object = '0';
    QChar Network::direction = '0';
    quint16 Network::angle = 0;

//Network * Network::instance = 0;

Network::Network() : QObject()
{
    qDebug() << "Building Network object";
    // инициализация начальных данных
    //keyWord = object = direction = '0';
    //angle = 0;

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    qDebug() << "Network object created";
}


void Network::recievingCommand()
{
    QDataStream in(tcpSocket);

    if (blockSize == 0) // только начинаме чтение данных
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;    // считали размер блока данных
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return; // ждем, пока данные прийдут полностью;
    else blockSize = 0;
    in >>  keyWord;
    if(keyWord!='I')    // если команда не "Сфотографировать"
    {
        in >> object;
        in >> direction;
        in >> angle;
    }
    qDebug() <<"\nWe have a new command! Here it is:\n ("<<keyWord<<" , "<<object<<" , "<<direction<<", "<<angle<<")\n";
}


void Network::listen()
{
    tcpServer->listen(QHostAddress::LocalHost, 5100); // от 0 до 1000 идут системные порты
    qDebug() << "Network object started listening";
}

void Network::onNewConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater(deleteLater())));
    connect(tcpSocket, SIGNAL(readyRead()), tcpServer, SLOT(recievingCommand()));
    qDebug() << "Network object accepted new command";
}
