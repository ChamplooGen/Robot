#ifndef BODY_H
#define BODY_H

#include "ICam.h"
#include "IEngine.h"
#include "Network.h"

class Body {
private:
    static Body * instance;
    Body();
	IEngine * leftEngine;
	IEngine * rightEngine;
	ICamera * camera;
public:
	~Body();
    static Body * getInstance(); // для вызова этих функцмя не нужен объект
    static void destroyInstance();

	IEngine * getLeftEngine();
	IEngine * getRightEngine();
	ICamera * getCamera();
};

#endif
