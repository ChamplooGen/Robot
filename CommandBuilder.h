#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H

#include "Cmd.h"
#include "Network.h"

class CommandBuilder
{
private:
    Network * network;
public:
   ~CommandBuilder();
    CommandBuilder();

    bool   HasNextCommand();
    ICMD * GetNextCommand();
    Network * GetNetwork() const { return network;}

};

#endif // COMMANDBUILDER_H

