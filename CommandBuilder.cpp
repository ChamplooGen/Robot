#include "CommandBuilder.h"

CommandBuilder::CommandBuilder()
{
    network = new Network();
    network->listen();

    qDebug() << "CommandBuilder object created";
}

bool CommandBuilder::HasNextCommand()   // не работает потому, что нет подключения
{
    if (network->GetKeyWord() != 'F') return true;
    else return false;
    //return false;   // !__NB__! создать функцию для опознавания того, что команда получена !__NB__!
}

ICMD * CommandBuilder::GetNextCommand()
{
    qDebug() <<"Trying to get new command";
    network->getCommand();
    qDebug() << network->GetKeyWord().toLatin1() << " " << network->GetObject().toLatin1(); // строка проверка того, что в текущей команде
    qDebug() <<"Got it. Trying to build it";
    CmdLeftEngine * cmd;
    cmd = new CmdLeftEngine();
    qDebug() <<"It was built";
    if (network->GetKeyWord() == 'T' && network->GetObject() == 'l') return cmd;       // !__NB__! создать функцию для получения новой команды !__NB__!
    else return 0;
}


CommandBuilder::~CommandBuilder()
{
    delete network;

    qDebug() << "CommandBuilder object destroyed";
}
