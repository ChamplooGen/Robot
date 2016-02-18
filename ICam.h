#ifndef ICAM_H
#define ICAM_H
#include "IEngine.h"

//____________Интерфейс камеры___________
class ICamera: public IEngine {
	public:
		virtual void GetImage() = 0;
		//virtual void Rotate(char Dir, int Angle = 0) = 0; - уже унаследован
};

#endif
