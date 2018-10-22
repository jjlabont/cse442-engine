#include "CollisionHandler.h"
#include "Entity.h"

//AABB Checking Collision
bool CheckCollision(Entity& e1, Entity& e2) { // AABB - AABB collision
	bool overlaps = false;
	if ((e1.sprite.x + e1.sprite.w >= e2.sprite.x && e2.sprite.x + e2.sprite.w >= e1.sprite.x) && (e1.sprite.y + e1.sprite.h >= e2.sprite.y &&
		e2.sprite.y + e2.sprite.h >= e1.sprite.y)) {
		if (e1.clayer == e2.clayer) {
			overlaps = true;
			return overlaps;
		}
	}
}

bool collision(Sprite& s1, Sprite& s2) {
	bool solid = false;

	if ((s1.x + s1.w >= s2.x && s2.x + s2.w >= s1.x) && (s1.y + s1.h >= s2.y &&
		s2.y + s2.h >= s1.y)) {
		solid = true;
		return solid;
	}

	return solid;
}

void collisionFix(Sprite& s1, Sprite& s2) {

}


//bool collision(Entity& e1, Entity& e2) {
//	bool solid = false;
//
//	if ((e1.sprite.x + e1.sprite.w >= e2.sprite.x && e2.sprite.x + e2.sprite.w >= e1.sprite.x) && (e1.sprite.y + e1.sprite.h >= e2.sprite.y &&
//		e2.sprite.y + e2.sprite.h >= e1.sprite.y)) {
//		solid = true;
//		return solid;
//	}
//
//	return solid;
//}

//bool collisionBase(Sprite& s1, Sprite& s2) {
//	bool solid = false;
//
//	if (((s1.y + s1.y) == true) || ((s1.x + s1.x) == true) || ((s1.x + s1.y) == true) ||
//		((s2.y + s2.y) == true) || ((s2.x + s2.x) == true) || ((s2.x + s2.y) == true)) {
//		solid = true;
//		return solid;
//	}
//
//	return solid;
//}

//bool collide(Entity& e1, Entity& e2) {
//	//Checks to see if e1 drawing and e2 drawing overlap
//	bool overlaps = false;
//	if ( ) {
//		//Checks to see if e1 collision layer and e2 collision layer are the same
//			//if they are, e1 and e2 are on same plane, therefore "collide"
//		if (e1.clayer == e2.clayer) {
//			overlaps = true;
//			return overlaps;
//		}
//	}
//	else {
//		return overlaps;
//	}
//}

bool isSolid() {
	return true;
}
