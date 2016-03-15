#ifndef CMDLEFTENGINE_H
#define CMDLEFTENGINE_H

#include "ICmd.h"
#include "Body.h"
#include "Network.h"

#include "Engine.h"

class CmdLeftEngine : public ICMD {
    public:
        void Execute();
};

#endif // CMDLEFTENGINE_H
