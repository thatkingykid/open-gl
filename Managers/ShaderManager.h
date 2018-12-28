#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

namespace Managers {
	class ShaderManager {
	private:
		std::string ReadShader(const std::string& file);
		GLuint CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
		static std::map<std::string, GLuint> programs;

	public:
		ShaderManager();
		~ShaderManager();
		void CreateProgram(const std::string& shaderName, std::string& vertexShaderFile, const std::string& fragmentShaderFile);
		static const GLuint GetShader(const std::string&);
	};
}