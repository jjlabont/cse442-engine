#pragma once
#include "Graphics.h"

//-----------------------------------------------------------------------------
//	SHADER CLASS
//-----------------------------------------------------------------------------
ShaderProgramSource::ShaderProgramSource(const std::string& filepath) {
	//file stream of shader file
	std::ifstream stream(filepath);

	//which shader in the file we are currently looking at
	enum class ShaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};


	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	//parse vs into ss[0], fs into ss[1]
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	vSource = ss[0].str();
	fSource = ss[1].str();
}

//-----------------------------------------------------------------------------
//	GRAPHIC SOURCE CLASS
//-----------------------------------------------------------------------------
GraphicSource::GraphicSource() {
	//vbo
	vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//ibo
	ibo = 0;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}

GraphicSource::~GraphicSource() {
	for (int i = 0; i < shader.size(); i++) {
		glDeleteProgram(shader[i]);
	}
}

void GraphicSource::addShader(const std::string& filepath) {
	ShaderProgramSource source = ShaderProgramSource("res/shaders/basic.shader");
	shader.push_back(CreateShader(source.vSource, source.fSource));
	glUseProgram(shader[0]);
}

void GraphicSource::queueSprite(Sprite sprite) {
	drawBatch.push_back(sprite);
}

void GraphicSource::draw() {
	std::vector<float> positions;
	std::vector<unsigned int> indicies;
	for (unsigned int i = 0; i < drawBatch.size(); i++) {

		//index 0
		positions.push_back(drawBatch[i].x);
		positions.push_back(drawBatch[i].y);

		//index 1
		positions.push_back(drawBatch[i].x + drawBatch[i].w);
		positions.push_back(drawBatch[i].y);

		//index 2
		positions.push_back(drawBatch[i].x + drawBatch[i].w);
		positions.push_back(drawBatch[i].y + drawBatch[i].h);

		//index 3
		positions.push_back(drawBatch[i].x);
		positions.push_back(drawBatch[i].y + drawBatch[i].h);

		indicies.push_back(i * 4 + 0);
		indicies.push_back(i * 4 + 1);
		indicies.push_back(i * 4 + 2);
		indicies.push_back(i * 4 + 2);
		indicies.push_back(i * 4 + 3);
		indicies.push_back(i * 4 + 0);
	}

	unsigned int numSprites = drawBatch.size();
	glBufferData(GL_ARRAY_BUFFER, numSprites * 6 * 2 * sizeof(float), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numSprites * 6 * sizeof(unsigned int), &indicies[0], GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 6 * numSprites, GL_UNSIGNED_INT, nullptr);

	drawBatch.clear();
}