#include "Entity.h"

Entity::Entity(Sprite sprite, float cl, bool iS) : sprite(sprite) {
	xPos = sprite.x;
	yPos = sprite.y;
	hPos = sprite.h;
	wPos = sprite.w;
	clayer = cl;
	isSolid = iS;
}
