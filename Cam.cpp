#include <iostream>
#include "Cam.h"

void Camera::GetImage ()	// реализацмя функции
{
	std::cout << "Here is a foto"<<std::endl;
} 

void Camera::Rotate (QChar Dir, quint16 Angle)	// реализацмя функции
{
    std::cout << "Rotating to "<<Dir.toLatin1()<<" at "<<Angle<<'\n';
} 
