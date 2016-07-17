#ifndef ENGINE_H
#define ENGINE_H
#include "IEngine.h"
#include <QChar>

class Engine: public IEngine {
	public:
        void Rotate(QChar Dir);
};

#endif
