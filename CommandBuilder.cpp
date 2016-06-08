#include "CommandBuilder.h"

CommandBuilder::CommandBuilder()
{
    network = new Network();
    network->listen();

    qDebug() << "CommandBuilder object created";
}

bool CommandBuilder::HasNextCommand()   // не работает потому, что нет подключения
{
    GetNetwork()->GetTcpSocket()->waitForReadyRead();
}

ICMD * CommandBuilder::GetNextCommand()
{
    qDebug() <<"Trying to get new command";
    network->getCommand();
    qDebug() <<"Got it. Trying to build it";

    Cmd * cmd;
    cmd = new Cmd();
    qDebug() <<"It was built";

// Эта строка пропускает лишь команды для поворота левого двигателя
//    if (network->GetKeyWord() == 'T' && network->GetObject() == 'l')
//    {
//        qDebug() << " This command tells to turn left engine";
//        return cmd;       // !__NB__! создать функцию для получения новой команды !__NB__!
//    }
//    else return 0;
    return cmd;
}


CommandBuilder::~CommandBuilder()
{
    delete network;

    qDebug() << "CommandBuilder object destroyed";
}
