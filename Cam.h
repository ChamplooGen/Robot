#ifndef CAM_H
#define CAM_H
#include "ICam.h"	// подключаем интерфейс

class Camera: public ICamera { // public Icamera - от кого наследуется
	public:
		void GetImage();
		void Rotate(QChar Dir, quint16 Angle = 0) ; // т.к. уже унаследован
};


#endif
