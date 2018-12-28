#pragma once
#include "Core/Init/InitGlut.h"
using namespace Core;
using namespace Init;

int main(int argc, char **argv) {
	WindowInfo window(std::string("OpenGL Tutorial Series"), 640, 480, 300, 300, true);
	ContextInfo context(4, 5, true);
	FrameBufferInfo frameBuffer(true, true, true, true);
	InitGlut::Init(window, context, frameBuffer);
	InitGlut::Run();

	return 0;
}