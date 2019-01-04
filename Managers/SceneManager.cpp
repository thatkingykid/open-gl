#include "SceneManager.h"
using namespace Managers;
SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shaderManager = new ShaderManager();
	std::string vertex = "Shaders\\VertexShader.glsl";
	std::string frag = "Shaders\\FragmentShader.glsl";
	shaderManager->CreateProgram("colorShader", vertex, frag);
}

SceneManager::~SceneManager()
{
	delete shaderManager;
}

void SceneManager::NotifyBeginFrame()
{

}

void SceneManager::NotifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void SceneManager::NotifyEndFrame()
{
}

void SceneManager::NotifyReshape(int width, int height, int previousWidth, int previousHeight)
{

}
