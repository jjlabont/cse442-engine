#include "Entity.h"

Entity::Entity(Sprite sprite) : sprite(sprite), speed(0.0f, 0.0f) {
}

Entity::~Entity() {

}

void Entity::setX(float x) {
	sprite.body.x = x;
}

float Entity::getX() const {
	return sprite.body.x;
}

void Entity::setY(float y) {
	sprite.body.y = y;
}

float Entity::getY() const {
	return sprite.body.y;
}

void Entity::setW(float w) {
	sprite.body.w = w;
}

float Entity::getW() const {
	return sprite.body.w;
}

void Entity::setH(float h) {
	sprite.body.h = h;
}

float Entity::getH() const {
	return sprite.body.h;
}

void Entity::setRot(float r) {
	sprite.rot = r;
}

float Entity::getRot() const {
	return sprite.rot;
}

void Entity::setSpeed(goat::vec2 s) {
	speed.x = s.x;
	speed.y = s.y;
}

goat::vec2 Entity::getSpeed() const {
	return speed;
}