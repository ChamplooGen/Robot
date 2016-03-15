#include <iostream>
#include "Engine.h"

void Engine::Rotate (QChar Dir, quint16 Angle)	// реализацмя функции
{
    std::cout << "Rotating to "<<Dir.toLatin1()<<" at "<<Angle<<"\n";
} 
