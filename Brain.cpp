#include "Network.h"
#include "CommandBuilder.h"
#include "Brain.h"

void Brain::start ()
{
    qDebug() << "Start main logic";
    qDebug() << "Start command processing";

    CommandBuilder commandBuilder;
    commandBuilder.GetNetwork()->GetTcpServer()->waitForNewConnection(60000);
    qDebug() <<"***********************************";
    while(commandBuilder.HasNextCommand()) {       // ATTENTION! : после непродолжительного безрезультатного ожидания команды программа оканчивает свою работу

//    qDebug() << "New command accepted, trying to execute";
    ICMD * cmd = commandBuilder.GetNextCommand();
    cmd->Execute();

//    qDebug() << "Command executed, waiting for next one\n";

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

