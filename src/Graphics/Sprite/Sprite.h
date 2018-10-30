#pragma once

#include "Util/DataTypes/DataTypes.h"

class Sprite {
private:
	std::vector<std::vector<float*>> vertexData;
public:
	Sprite();
	Sprite(goat::Rect body, goat::Color c, goat::Rect texCoords = goat::Rect());

	void prepVertexData(int vertexCount, int span);
	void setVertexData(std::vector<std::vector<float*>> d);
	void updateVertexData();

	goat::Rect body;
	goat::Color color;
	goat::Rect texCoords;
	goat::vec3 rot;
};