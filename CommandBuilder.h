#ifndef COMMANDBUILDER_H
#define COMMANDBUILDER_H
#include "ICmd.h"

class CommandBuilder: public ICMD
{
public:
    CommandBuilder();
    bool HasNextCommand();
    ICMD GetNextCommand();

};

#endif // COMMANDBUILDER_H
