#include "InitGlut.h"

using namespace Core::Init;

void InitGlut::Init(const Core::WindowInfo & window, const Core::ContextInfo & context, const Core::FrameBufferInfo & frameBuffer)
{
	int fakeargc = 1;
	char *fakeargv[] = {(char*)"fake" , NULL };
	glutInit(&fakeargc, fakeargv);

	if (context.core) {
		glutInitContextVersion(context.majorVersion, context.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	} else {
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(frameBuffer.flags);
	glutInitWindowPosition(window.positionX, window.positionY);
	glutInitWindowSize(window.width, window.height);
	glutCreateWindow(window.name.c_str());

	std::cout << "GLUT: Initialised" << std::endl;
	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);


	Init::InitGlew::Init();
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	PrintGLInfo(window, context);
}

void InitGlut::Run()
{
	std::cout << "GLUT: Entered Main Loop" << std::endl;
	glutMainLoop();
}

void InitGlut::Close()
{
	std::cout << "GLUT: Leaving Main Loop" << std::endl;
	glutLeaveMainLoop();
}

void InitGlut::EnterFullscreen()
{
	glutFullScreen();
}

void InitGlut::ExitFullscreen()
{
	glutLeaveFullScreen();
}

void InitGlut::PrintGLInfo(const Core::WindowInfo & window, const Core::ContextInfo & context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "=====================================" << std::endl;
	std::cout << "GLUT Version: " << version << std::endl;
	std::cout << "GLUT Renderer: " << renderer << std::endl;
	std::cout << "GLUT Vendor: " << vendor << std::endl;
}

void InitGlut::IdleCallback(void)
{
	glutPostRedisplay();
}

void InitGlut::DisplayCallback(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();
}

void InitGlut::ReshapeCallback(int width, int height)
{
}

void InitGlut::CloseCallback()
{
	Close();
}
