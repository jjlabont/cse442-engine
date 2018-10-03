#pragma once
#include "Entity.h"
#include "GOAT_Engine.h"

class collide {
	Entity& e1;
	Entity& e2;
	float cLayer;
	float sLayer;

	collide(Entity & e1, Entity & e2, float cl, bool sLayer);
	~collide();
};

bool isCollision(Entity& e1, Entity& e2);