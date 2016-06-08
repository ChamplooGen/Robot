#ifndef IENGINE_H
#define IENGINE_H
#include <QChar>

//____________Интерфейс мотора___________
class IEngine {
	public:
        virtual void Rotate(QChar Dir) = 0;
		// Dir = {U, D, R, L}
		// Angle = [0; 180)
};

#endif
