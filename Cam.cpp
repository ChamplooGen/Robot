#include <iostream>
#include "Cam.h"

void Camera::GetImage ()	// реализацмя функции
{
	std::cout << "Here is a foto"<<std::endl;
} 

void Camera::Rotate (char Dir, int Angle)	// реализацмя функции
{
	std::cout << "Rotating to "<<Dir<<" at "<<Angle<<std::endl;
} 
