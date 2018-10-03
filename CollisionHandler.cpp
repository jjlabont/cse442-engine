#include "CollisionHandler.h"

bool isCollision(Entity& e1, Entity& e2) {
	//bool sameLayer = false;
	
	//Checks to see if e1 drawing and e2 drawing overlap
	if ((e1.x < e2.x + e2.w) && (e1.x + e1.w > e2.x) && (e1.y < e2.y + e2.h) && (e1.y + e1.h > e2.y)) {
	//Checks to see if e1 collision layer and e2 collision layer are the same
		//if they are, e1 and e2 are on same plane, therefore "collide"
		if (e1.cl == e2.cl) {
			return true;
		}
	}
	else {
		return false;
	}
}