#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

namespace Core {
	class ShaderLoader {
	private:
		std::string ReadShader(char *file);
		GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);

	public:
		ShaderLoader();
		~ShaderLoader();
		GLuint CreateProgram(char* vertexShaderFile, char* fragmentShaderFile);
	};
}