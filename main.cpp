#pragma once
#include "Core/Init/InitGlut.h"
#include "Managers/SceneManager.h"
using namespace Core;
using namespace Init;

extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

int main(int argc, char **argv) {
	WindowInfo window(std::string("OpenGL Tutorial Series"), 640, 480, 300, 300, true);
	ContextInfo context = ContextInfo(4, 5, true);
	FrameBufferInfo frameBuffer(true, true, true, true);
	InitGlut::Init(window, context, frameBuffer);

	IListener* scene = new Managers::SceneManager();
	Init::InitGlut::SetListener(scene);

	InitGlut::Run();

	delete scene;
	return 0;
}