#include "ShaderManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace Managers;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager() {}
ShaderManager::~ShaderManager() {
	std::map<std::string, GLuint>::iterator i;
	for (i = programs.begin(); i != programs.end(); i++) {
		GLuint pr = i->second;
		glDeleteProgram(pr);
	}
	programs.clear();
}

std::string ShaderManager::ReadShader(const std::string& file) {
	std::string shaderCode;
	std::ifstream fileStream(file, std::ios::in);

	if (!fileStream.good()) {
		std::cout << "Can't read file" << file.c_str() << std::endl;
		std::terminate();
	}

	fileStream.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)fileStream.tellg());
	fileStream.seekg(0, std::ios::beg);
	fileStream.read(&shaderCode[0], shaderCode.size());
	fileStream.close();
	return shaderCode;
}

GLuint ShaderManager::CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName) {
	int compileResult = 0;
	GLuint shader = glCreateShader(shaderType);
	const char *shaderPtr = source.c_str();
	const int shaderSize = source.size();

	glShaderSource(shader, 1, &shaderPtr, &shaderSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE) {
		int logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> shaderLog(logLength);
		glGetShaderInfoLog(shader, logLength, NULL, &shaderLog[0]);
		std::cout << "SHADER COMPILER ERROR: " << shaderName.c_str() << std::endl << &shaderLog[0] << std::endl;
		return 0;
	}

	return shader;
}

void ShaderManager::CreateProgram(const std::string& shaderName, std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
	std::string vertexShaderCode = ReadShader(vertexShaderFile);
	std::string fragmentShaderCode = ReadShader(fragmentShaderFile);

	char vertexName[] = "vertex shader";
	char fragmentName[] = "fragment shader"; 
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderCode, vertexName);
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode, fragmentName);

	int linkResult = 0;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);
	if (linkResult == GL_FALSE) {
		int logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetProgramInfoLog(program, logLength, NULL, &log[0]);
		std::cout << "SHADER LINK ERROR" << std::endl << &log[0] << std::endl;
		return;
	}
	programs[shaderName] = program;
}

const GLuint ShaderManager::GetShader(const std::string& shaderName) {
	//todo: validate shader name
	return programs.at(shaderName);
}