#include "Sprite.h"

Sprite::Sprite() : body(goat::Rect()), color(goat::Color()), texCoords(goat::Rect()), rot(0.0f, 0.0f, 0.0f) {
}
Sprite::Sprite(goat::Rect body, goat::Color c, goat::Rect texCoords) : body(body), color(c), texCoords(texCoords), rot(0.0f, 0.0f, 0.0f) {
}


void Sprite::prepVertexData(int vertexCount, int span) {
	vertexData.resize(vertexCount);
	for (int i = 0; i < vertexCount; i++) {
		vertexData[i].resize(span);
	}
}

//assume d.size() > 0
void Sprite::setVertexData(std::vector<std::vector<float*>> d) {
	prepVertexData(d.size(), d[0].size());
	for (int i = 0; i < vertexData.size(); i++) {
		for (int j = 0; j < vertexData[i].size(); j++) {
			vertexData[i][j] = d[i][j];
		}
	}
}

void Sprite::updateVertexData() {
	//vertex 0
	/////////////////////////////////////////////////////
	//position
	*vertexData[0][0] = -0.5f;
	*vertexData[0][1] = -0.5f;
	//texCoord
	*vertexData[0][2] = texCoords.x;
	*vertexData[0][3] = texCoords.y;
	//rotation
	*vertexData[0][4] = rot.x;
	*vertexData[0][5] = rot.y;
	*vertexData[0][6] = rot.z;
	//scale
	*vertexData[0][7] = body.w;
	*vertexData[0][8] = body.h;
	//translation
	*vertexData[0][9] = body.x;
	*vertexData[0][10] = body.h;

	//vertex 1
	/////////////////////////////////////////////////////
	//position
	*vertexData[1][0] = 0.5f;
	*vertexData[1][1] = -0.5f;
	//texCoord
	*vertexData[1][2] = texCoords.x + texCoords.w;
	*vertexData[1][3] = texCoords.y;
	//rotation
	*vertexData[1][4] = rot.x;
	*vertexData[1][5] = rot.y;
	*vertexData[1][6] = rot.z;
	//scale
	*vertexData[1][7] = body.w;
	*vertexData[1][8] = body.h;
	//translation
	*vertexData[1][9] = body.x;
	*vertexData[1][10] = body.h;

	//vertex 2
	/////////////////////////////////////////////////////
	//position
	*vertexData[2][0] = 0.5f;
	*vertexData[2][1] = 0.5f;
	//texCoord
	*vertexData[2][2] = texCoords.x + texCoords.w;
	*vertexData[2][3] = texCoords.y + texCoords.h;
	//rotation
	*vertexData[2][4] = rot.x;
	*vertexData[2][5] = rot.y;
	*vertexData[2][6] = rot.z;
	//scale
	*vertexData[2][7] = body.w;
	*vertexData[2][8] = body.h;
	//translation
	*vertexData[2][9] = body.x;
	*vertexData[2][10] = body.h;

	//vertex 3
	/////////////////////////////////////////////////////
	//position
	*vertexData[3][0] = -0.5f;
	*vertexData[3][1] = 0.5f;
	//texCoord
	*vertexData[3][2] = texCoords.x;
	*vertexData[3][3] = texCoords.y + texCoords.h;
	//rotation
	*vertexData[3][4] = rot.x;
	*vertexData[3][5] = rot.y;
	*vertexData[3][6] = rot.z;
	//scale
	*vertexData[3][7] = body.w;
	*vertexData[3][8] = body.h;
	//translation
	*vertexData[3][9] = body.x;
	*vertexData[3][10] = body.h;
}