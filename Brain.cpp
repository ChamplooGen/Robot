#include <iostream>
#include "Cam.h"
#include "Brain.h"
#include "network.h"

void Brain::start ()	// реализацмя функции
{
    std::cout << "I'm working!\n";
    IEngine * left = Body::getInstance()->getLeftEngine();// Body::getInstance() получаем ссылку на единственный
    left->Rotate('R', 58);
    ICamera * camera = Body::getInstance()->getCamera();
    camera->GetImage();
    std::cout<<"\n";
    Network::GetInstance()->Connect();
    Network::GetInstance()->Get();
    Network::GetInstance()->Listen();
    Network::GetInstance()->Send();
    Network::GetInstance()->Disconnect();
    IEngine * right = Body::getInstance()->getRightEngine();
    right->Rotate('R', 58);




//    while(commandBuilder.hasNextCommand()) {
//        ICommand * cmd = commandBuilder.getNextCommand();
//        cmd->execute();
//    }
} 
