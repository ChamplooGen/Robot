#ifndef CAM_H
#define CAM_H
#include "ICam.h"	// подключаем интерфейс

class Camera: public ICamera { // public Icamera - от кого наследуется
	public:
		void GetImage();
		void Rotate(char Dir, int Angle = 0) ; // т.к. уже унаследован
};


#endif
