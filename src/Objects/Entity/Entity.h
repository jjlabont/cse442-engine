#pragma once
#include <tuple>

class Entity {
private:
	

public:
	float xPosition;
	float yPosition;
	float width;
	float height;

	Entity(float xPos, float yPos, float w, float h);
	~Entity();

};