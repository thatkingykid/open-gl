#include "InitGlew.h"
using namespace Core;
using namespace Core::Init;

void InitGlew::Init() {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		std::cout << "GLEW: Initialised" << std::endl;
	}
	if (glewIsSupported("GL_VERSION_4_5")) {
		std::cout << "GLEW: 4.5 is supported" << std::endl;
	} else {
		std::cout << "GLEW: 4.5 is not supported" << std::endl;
	}
}