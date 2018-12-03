#pragma once

#include "Util/DataTypes.h"
#include "Graphics/Texture/Texture.h"
#include <glm/glm.hpp>
#include <string>

class Animation {
	goat::Rect baseFrame;
	int numFrames;
	float frameTime;
	float currentTime;

	std::string name;
public:
	Animation(std::string name, goat::Rect baseFrame, int numFrames, float frameTime);
	float GetX();
	float GetY();
	float GetW();
	float GetH();
	void addTime(float d);

	std::string getName();

};