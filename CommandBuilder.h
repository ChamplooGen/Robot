#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H
#include "ICmd.h"
#include "network.h"

class CommandBuilder
{
private:
    Network *network;
public:
    ~CommandBuilder();
    CommandBuilder();
    bool HasNextCommand();
    ICMD *GetNextCommand();

};

#endif // COMMANDBUILDER_H

