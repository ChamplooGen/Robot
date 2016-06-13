#include "CommandBuilder.h"

CommandBuilder::CommandBuilder()
{
    network = new Network();
    network->listen();

    qDebug() << "CommandBuilder object created";
}

bool CommandBuilder::HasNextCommand()
{
    GetNetwork()->GetTcpSocket()->waitForReadyRead();
}

ICMD * CommandBuilder::GetNextCommand()
{
    network->getCommand();

    Cmd * cmd;
    cmd = new Cmd();

    return cmd;
}


CommandBuilder::~CommandBuilder()
{
    delete network;

    qDebug() << "CommandBuilder object destroyed";
}
