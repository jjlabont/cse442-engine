#pragma once
#include <tuple>
#include "Graphics.h"
//#include "GOAT_Engine.h"
class Entity {
private:

public:
	Sprite sprite;
	//float xPos;
	//float yPos;
	//float wPos;
	//float hPos;
	float clayer;

	Entity(Sprite s1, float clayer);
	//before:
	//	Entity(Sprite s1, float xPos, float yPos, float wPos, float hPos, float clayer);
	//~Entity();

};