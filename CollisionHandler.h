#pragma once
#include "Entity.h"

class collide {
	Entity& e1;
	Entity& e2;
	float collisionLayer;
	float sLayer;

	collide(Entity & e1, Entity & e2, float collisionLayer, bool sLayer);
	//~collide();
};

//bool isCollision(Entity& e1, Entity& e2);
bool collision(Sprite& s1, Sprite& s2);
bool CheckCollision(Entity& e1, Entity& e2);

bool isSolid();

