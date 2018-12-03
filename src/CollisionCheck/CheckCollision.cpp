#pragma once

int aaasdf = 5;
#include <tuple>
#include <string>
#include "Graphics/Graphics.h"
#include "Input/Input.h"
#include "Objects/Entity/Entity.h"
#include "CollisionCheck/CheckCollision.h"


void collideX(Entity& e1, Entity& e2) {
	e1.collision = ((e1.getX()) < (e2.getX()) + (e2.getW())) && ((e1.getX()) + (e1.getW()) > (e2.getX()))
		&& ((e1.getY()) < (e2.getY()) + (e2.getH())) && ((e1.getY()) + (e1.getH()) > (e2.getY()));

	//right side collision
	if ((e1.collision > 0) && ((e1.getSpeed().x) > 0)) {
		e1.rightC = true;
	}
	else {
		e1.rightC = false;
	}

	//left side collision
	if ((e1.collision > 0) && (e1.getSpeed().x) < 0) {
		e1.leftC = true;
	}
	else {
		e1.leftC = false;
	}
}

void collideY(Entity& e1, Entity& e2) {
	e1.collision = (e1.getX() < e2.getX() + e2.getW()) && (e1.getX() + e1.getW() > e2.getX())
		&& (e1.getY() < e2.getY() + e2.getH()) && (e1.getY() + e1.getH() > e2.getY());

	//top side collision
	if ((e1.collision > 0) && ((e1.getSpeed().y) > 0)) {
		e1.topC = true;
	}
	else {
		e1.topC = false;
	}

	//bottom side collision
	if ((e1.collision < 0)&& (e1.getSpeed().y < 0)) {
		e1.botC = true;
	}
	else {
		e1.botC = false;
	}
}
