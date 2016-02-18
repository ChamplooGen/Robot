#ifndef IENGINE_H
#define IENGINE_H

//____________Интерфейс мотора___________
class IEngine {
	public:
		virtual void Rotate(char Dir, int Angle) = 0;
		// Dir = {U, D, R, L}
		// Angle = [0; 180)
};

#endif
