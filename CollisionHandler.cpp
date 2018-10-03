#include "CollisionHandler.h"

bool isCollision(Entity& e1, Entity& e2) {	
	//Checks to see if e1 drawing and e2 drawing overlap
	if ((e1.sprite.x < e2.sprite.x + e2.sprite.w) && (e1.sprite.x + e1.sprite.w > e2.sprite.x) && (e1.sprite.y < e2.sprite.y + e2.sprite.h) 
		&& (e1.sprite.y + e1.sprite.h > e2.sprite.y)) {
	//Checks to see if e1 collision layer and e2 collision layer are the same
		//if they are, e1 and e2 are on same plane, therefore "collide"
		if (e1.clayer == e2.clayer) {
			return true;
		}
	}
	else {
		return false;
	}
}

	//(e1.sprite.x < e2.sprite.x + e2.sprite.w) && (e1.sprite.x + e1.sprite.w > e2.sprite.x) &&
	//(e1.sprite.y < e2.sprite.y + e2.sprite.h) && (e1.sprite.y + e1.sprite.h > e2.sprite.y)