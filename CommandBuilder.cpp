#include "commandbuilder.h"

CommandBuilder::CommandBuilder()
{
    network = new Network();
    network->listen();
}

bool CommandBuilder::HasNextCommand()
{

}

ICMD *CommandBuilder::GetNextCommand()
{
    return 0;
}


CommandBuilder::~CommandBuilder()
{
    delete network;
}
