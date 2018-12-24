#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "Core\VertexFormat.h"
#include <vector>
#include <map>

namespace Models {
	struct Model {
		unsigned int vao;
		std::vector<unsigned int> vbos;
	};

	class GameModels {
	public:
		GameModels();
		~GameModels();
		void CreateTriangleModel(const std::string& modelName);
		void DeleteModel(const std::string& modelName);
		unsigned int GetModel(const std::string& modelName);
	private:
		std::map<std::string, Model> modelList;
	};
}