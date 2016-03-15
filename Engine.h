#ifndef ENGINE_H
#define ENGINE_H
#include "IEngine.h"

class Engine: public IEngine {
	public:
		void Rotate(QChar Dir, quint16 Angle);
};

#endif
