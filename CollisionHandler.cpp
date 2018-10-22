#include "CollisionHandler.h"


//AABB Checking Collision Entity Method
bool CheckCollision(Entity& e1, Entity& e2) { // AABB - AABB collision
	bool solid = false;
	//std::cout << e1.sprite.x << e2.sprite.x << std::endl;
	std::cout << (e1.sprite.x + e1.sprite.w >= e2.sprite.x) << std::endl;
	if ((e1.sprite.x + e1.sprite.w >= e2.sprite.x && e2.sprite.x + e2.sprite.w >= e1.sprite.x) && (e1.sprite.y + e1.sprite.h >= e2.sprite.y &&
			e2.sprite.y + e2.sprite.h >= e1.sprite.y)) {
		return true;
	}
	return solid;
}

//original if statement:
//if ((e1.sprite.x + e1.sprite.w >= e2.sprite.x && e2.sprite.x + e2.sprite.w >= e1.sprite.x) && (e1.sprite.y + e1.sprite.h >= e2.sprite.y &&
//	e2.sprite.y + e2.sprite.h >= e1.sprite.y)) {

//original layer check
		//if (e1.clayer == e2.clayer) {
		//	overlaps = true;
		//	return overlaps;
		//}

//AABB Checking Collision Sprite Method
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

bool isSolid() {
	return true;
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

