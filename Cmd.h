#ifndef CMD_H
#define CMD_H

#include "ICmd.h"
#include "Body.h"
#include "Network.h"

#include "Engine.h"

class Cmd : public ICMD {
    public:
        void Execute();
};

#endif // CMD_H
