#include "Entity.h"

Entity::Entity(std::string name, Sprite sprite) :
	name(name), sprite(sprite), speed(0.0f, 0.0f),
	animation(Animation("", goat::Rect(0, 0, 1, 1), 1, 0 )) {
}

Entity::Entity(const Entity& e) : animation(Animation("", goat::Rect(0, 0, 1, 1), 1, 0)) {
	Entity(e.name, e.sprite);
}

Entity::~Entity() {

}

std::string Entity::getName() const {
	return name;
}

///////////////////////////////////////////////////////////////////////////////
//POSITION/SIZE
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//MOVEMENT
///////////////////////////////////////////////////////////////////////////////
void Entity::setRotX(float x) {
	sprite.rot.x = x;
}

float Entity::getRotX() const {
	return sprite.rot.x;
}

void Entity::setRotY(float y) {
	sprite.rot.y = y;
}

float Entity::getRotY() const {
	return sprite.rot.y;
}

void Entity::setRotZ(float z) {
	sprite.rot.z = z;
}

float Entity::getRotZ() const {
	return sprite.rot.z;
}

///////////////////////////////////////////////////////////////////////////////
//MOVEMENT
///////////////////////////////////////////////////////////////////////////////

void Entity::setSpeed(goat::vec2 s) {
	speed.x = s.x;
	speed.y = s.y;
}

goat::vec2 Entity::getSpeed() const {
	return speed;
}

///////////////////////////////////////////////////////////////////////////////
//TEX COORDS
///////////////////////////////////////////////////////////////////////////////
void Entity::setTexCoordsX(float x) {
	sprite.texCoords.x = x;
}

float Entity::getTexCoordsX() const {
	return sprite.texCoords.x;
}

void Entity::setTexCoordsY(float y) {
	sprite.texCoords.y = y;
}

float Entity::getTexCoordsY() const {
	return sprite.texCoords.y;
}

void Entity::setTexCoordsW(float w) {
	sprite.texCoords.w = w;
}

float Entity::getTexCoordsW() const {
	return sprite.texCoords.w;
}

void Entity::setTexCoordsH(float h) {
	sprite.texCoords.h = h;
}

float Entity::getTexCoordsH() const {
	return sprite.texCoords.h;
}

///////////////////////////////////////////////////////////////////////////////
//ANIMATION
///////////////////////////////////////////////////////////////////////////////

void Entity::animateWithDelta(float d)
{
	animation.addTime(d);
	sprite.texCoords.x = animation.GetX();
}

void Entity::setAnimation(Animation animation) {
	sprite.texCoords.x = animation.GetX();
	sprite.texCoords.y = animation.GetY();
	sprite.texCoords.w = animation.GetW();
	sprite.texCoords.h = animation.GetH();

	this->animation = animation;
}

std::string Entity::getAnimationName() {
	return animation.getName();
}

///////////////////////////////////////////////////////////////////////////////
//OPERATORS
///////////////////////////////////////////////////////////////////////////////
/*Entity& operator=(Entity e) {
	Entity r = Entity()
}*/
