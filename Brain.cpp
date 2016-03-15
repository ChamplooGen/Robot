#include "Cam.h"
#include "Brain.h"
#include "Network.h"
#include "CommandBuilder.h"

void Brain::start ()
{
    qDebug() << "Start main logic";
    qDebug() << "Start command processing";

    CommandBuilder commandBuilder;
    while(commandBuilder.HasNextCommand()) {
        qDebug() << "New command accepted, trying to execute";

        ICMD * cmd = commandBuilder.GetNextCommand();
        qDebug() << "Next step";
        cmd->Execute();

        qDebug() << "Command executed, waiting for next one";
    }

    qDebug() << "Stop command processing";
} 


    // std::cout << "I'm working!\n";
    // IEngine * left = Body::getInstance()->getLeftEngine();// Body::getInstance() получаем ссылку на единственный
    // left->Rotate('R', 58);
    // ICamera * camera = Body::getInstance()->getCamera();
    // camera->GetImage();
    // std::cout<<"\n";
    // CommandBuilder commandBuilder;

