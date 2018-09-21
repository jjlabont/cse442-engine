#pragma once
#include <tuple>

class Entity {
private:
	float xPosition;
	float yPosition;
	float width;
	float height;

public:

	Entity(float xPos, float yPos, float w, float h);

	std::tuple<float, float> getPosition();

	bool setPosition(float xPos, float yPos);
};