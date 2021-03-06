#include "Network.h"
#include <iostream>
//#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

    QChar Network::keyWord = '-1';
    QChar Network::type = '-1';
    QChar Network::direction = '-1';
    //quint16 Network::angle = 0;

//Network * Network::instance = 0;

Network::Network() : QObject()
{
    qDebug() << "Building Network object";

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    commandIsReady = false;
    qDebug() << "Network object created";
}


void Network::recievingCommand()
{
    QDataStream in(tcpSocket);

    if (blockSize == 0) // только начинаем чтение данных
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;    // считали размер блока данных
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return; // ждем, пока данные прийдут полностью;
    else blockSize = 0;

    in >> keyWord;
// Даже если команда "Сфотографировать", считываем фиктивные параметры в object и direction
    in.skipRawData(4);
    in >> type;
    in >> direction;

    commandIsReady = true;
// Строка проверки правильности приема команды
    //qDebug() <<"\nWe have a new command! Here it is:\n ("<<keyWord.toLatin1()<<" , "<<object.toLatin1()<<" , "<<direction.toLatin1()<</*", "<<angle<<*/")\n";
}


void Network::listen()
{
    tcpServer->listen(QHostAddress::Any, 5100); // от 0 до 1000 идут системные порты
    qDebug() << "Network object started listening";
}

void Network::getCommand()
{
    while (IsCommandReady() == false)
    {
        recievingCommand(); // пока команда не готова, пытаемся ее получить
    }
    commandIsReady = false; // как только получили, обнулили индикатор готовности
}

void Network::onNewConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater(deleteLater())));
    connect(tcpSocket, SIGNAL(readyRead()), tcpServer, SLOT(recievingCommand()));
    if (tcpSocket != NULL) qDebug() << "Connection established.";
}
