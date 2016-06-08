#ifndef CAM_H
#define CAM_H
#include "ICam.h"	// подключаем интерфейс
#include <QChar>

class Camera: public ICamera { // public Icamera - от кого наследуется
	public:
		void GetImage();
        void Rotate(QChar Dir) ; // т.к. уже унаследован
};


#endif
