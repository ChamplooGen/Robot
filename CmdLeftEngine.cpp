#include "CmdLeftEngine.h"

void CmdLeftEngine::Execute()
{
    IEngine * leftEngine = Body::getInstance()->getLeftEngine();
    leftEngine->Rotate( Network::GetDirection(), Network::GetAngle());
}
