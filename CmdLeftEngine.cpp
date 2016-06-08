#include "Cmd.h"
#include <iostream> // для проверки

void Cmd::Execute()
{
    switch(Network::GetKeyWord().toLatin1())       // распознаем ключевое слово
    {
    case 'T':
        switch (Network::GetObject().toLatin1())
        {
            case 'l':
            {
                IEngine * leftEngine = Body::getInstance()->getLeftEngine();
                std::cout << Network::GetObject().toLatin1() << ": ";
                return leftEngine->Rotate(Network::GetDirection());
            }
                break;

            case 'r':
            {
                IEngine * rightEngine = Body::getInstance()->getRightEngine();
                std::cout << Network::GetObject().toLatin1() << ": ";
                return rightEngine->Rotate(Network::GetDirection());
            }
                break;
            default:
            {
                qDebug() << "Engine error: wrong object argument";
                return;
            }
                break;
        };

    case 'I':
        {
            ICamera * camera = Body::getInstance()->getCamera();
            return camera->GetImage();
        }
    default:
        qDebug() << "Cmd error: wrong keyword argument";
    }
}
