#include "Entity.h"

Entity::Entity(float xPos, float yPos, float h, float w) {
	xPosition = xPos;
	yPosition = yPos;
	height = h;
	width = w;
}

std::tuple<float, float> Entity::getPosition() {
	float x = Entity::xPosition;
	float y = yPosition;
	std::tuple<float, float> retVal = std::tuple<float, float>(x, y);
	return retVal;
}

bool Entity::setPosition(float xPos, float yPos) {
	xPosition = xPos;
	yPosition = yPos;
	return true;
}