#include "Models\GameModels.h"
using namespace Models;

GameModels::GameModels() {

}

GameModels::~GameModels() {
	std::map<std::string, Model>::iterator it;
	for (it = modelList.begin(); it != modelList.end(); ++it) {
		unsigned int* p = &it->second.vao;
		glDeleteVertexArrays(1, p);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	modelList.clear();
}

void GameModels::CreateTriangleModel(const std::string& modelName) {
	unsigned int vao;
	unsigned int vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(0.25, -0.25, 0.0)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, -0.25, 0.0)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.25, 0.0)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);

	Model myModel;
	myModel.vao = vao;
	myModel.vbos.push_back(vbo);
	modelList[modelName] = myModel;
}

void GameModels::DeleteModel(const std::string& modelName) {
	Model model = modelList[modelName];
	unsigned int p = model.vao;
	glDeleteVertexArrays(1, &p);
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);
	model.vbos.clear();
	modelList.erase(modelName);
}

unsigned int GameModels::GetModel(const std::string& modelName) {
	return modelList[modelName].vao;
}