#include <gl\glew.h>
#include <gl\freeglut.h>
#include <iostream>

#include "Core\ShaderLoader.h";
#include "Models\GameModels.h"
using namespace Core;

GLuint program;
Models::GameModels* gameModels;

void glRenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	glBindVertexArray(gameModels->GetModel("triangle1"));
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

void closeCallback() {
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init() {
	glEnable(GL_DEPTH_TEST);
	Core::ShaderLoader shaderLoader;

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	char vertexShader[] = "Shaders\\VertexShader.glsl";
	char fragShader[] = "Shaders\\FragmentShader.glsl";
	program = shaderLoader.CreateProgram(vertexShader, fragShader);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(640, 480);
	glutCreateWindow("My first window!");

	glewInit();
	Init();
	glutDisplayFunc(glRenderScene);
	glutCloseFunc(closeCallback);
	glutMainLoop();

	delete gameModels;
	glDeleteProgram(program);
	return 0;
}