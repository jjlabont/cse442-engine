#pragma once
#include <tuple>
#include "Graphics.h"

class Entity {
private:

public:
	Sprite sprite;
	float xPos;
	float yPos;
	float wPos;
	float hPos;
	float clayer;
	bool isSolid;

	Entity(Sprite sprite, float clayer, bool isSolid);

};
