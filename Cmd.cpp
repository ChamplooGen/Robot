#include "Cmd.h"
#include <iostream> // для проверки

void Cmd::Execute()
{
    if(Network::GetKeyWord().toLatin1() == 'M')       // распознаем ключевое слово
    {


        if (Network::GetType().toLatin1() == 'S')   // Остановить моторы
        qDebug() << "   Stop the engines";
        else if (Network::GetType().toLatin1() == 'R')       // Запустить моторы
                {
                    switch (Network::GetDirection().toLatin1())
                    {
                        case 'F':
                        qDebug() << "   Go forward";
                        break;

                        case 'B':
                        qDebug() << "   Go back";
                        break;

                        case 'L':
                        qDebug() << "   Go left";
                        break;

                        case 'R':
                        qDebug() << "   Go right";
                        break;

                        default:
                        qDebug() << "Move error: wrong direction argument";
                        break;
                    }

                }
                else qDebug() << "Move error: wrong movement type argument";


                        //            case 'l':
                        //            {
                        //                IEngine * leftEngine = Body::getInstance()->getLeftEngine();
                        //                std::cout << Network::GetObject().toLatin1() << ": ";
                        //                return leftEngine->Rotate(Network::GetDirection());
                        //            }
                        //                break;

                        //            case 'r':
                        //            {
                        //                IEngine * rightEngine = Body::getInstance()->getRightEngine();
                        //                std::cout << Network::GetObject().toLatin1() << ": ";
                        //                return rightEngine->Rotate(Network::GetDirection());
                        //            }
                        //                break;
                        //            default:
                        //            {
                        //                qDebug() << "Engine error: wrong object argument";
                        //                return;
                        //            }
                        //                break;

    }
    else if(Network::GetKeyWord().toLatin1() == 'I')
            {
                ICamera * camera = Body::getInstance()->getCamera();
                return camera->GetImage();
            }
         else qDebug() << "Cmd error: wrong keyword argument";

}
