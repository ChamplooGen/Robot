#include "Body.h"
#include "Engine.h"
#include "Cam.h"
#include "Net.h"

Body * Body::instance = 0;

Body::Body() {
	leftEngine = new Engine();
	rightEngine = new Engine();
	camera = new Camera();
}

Body::~Body() {
	delete camera;
	delete leftEngine;
	delete rightEngine;
}

void Body::destroyInstance() {
    if(instance != 0)
        delete instance;
}

Body * Body::getInstance() {
    if(instance == 0)
        instance = new Body();

    return instance;
}

IEngine * Body::getLeftEngine() {
	return leftEngine;
}

	
IEngine * Body::getRightEngine() {
	return rightEngine;
}

ICamera * Body::getCamera() {
	return camera;
}
