#include "CommandBuilder.h"

CommandBuilder::CommandBuilder()
{
    network = new Network();
    network->listen();

    qDebug() << "CommandBuilder object created";
}

bool CommandBuilder::HasNextCommand()   // не работает потому, что нет подключения
{
    if (network->GetKeyWord() == 'F') return false;
    else return true;
    //return false;   // !__NB__! создать функцию для опознавания того, что команда получена !__NB__!
}

ICMD * CommandBuilder::GetNextCommand()
{
    qDebug() <<"Trying to get new command";
    network->getCommand();
    qDebug() <<"Got it. Trying to build it";
    CmdLeftEngine * cmd;
    cmd = new CmdLeftEngine();
    qDebug() <<"It was built";
    return cmd;       // !__NB__! создать функцию для получения новой команды !__NB__!
}


CommandBuilder::~CommandBuilder()
{
    delete network;

    qDebug() << "CommandBuilder object destroyed";
}
