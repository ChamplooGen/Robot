#include <iostream>
#include <iostream>
#include "Cam.h"
#include "Brain.h"
#include "network.h"
#include "commandbuilder.h"

void Brain::start ()	// реализацмя функции
{
    std::cout << "I'm working!\n";
    IEngine * left = Body::getInstance()->getLeftEngine();// Body::getInstance() получаем ссылку на единственный
    left->Rotate('R', 58);
    ICamera * camera = Body::getInstance()->getCamera();
    camera->GetImage();
    std::cout<<"\n";
    CommandBuilder commandBuilder;


    //std::cin.get();

//    while(commandBuilder.hasNextCommand()) {
//        ICommand * cmd = commandBuilder.getNextCommand();
//        cmd->execute();
//    }
} 
