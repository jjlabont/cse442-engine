#include "Entity.h"

Entity::Entity(std::string name, Sprite sprite) : name(name), sprite(sprite), speed(0.0f, 0.0f) {
}

Entity::Entity(const Entity& e) : name(e.name), sprite(e.sprite), speed(e.speed) {
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
//RENDERING
///////////////////////////////////////////////////////////////////////////////
void Entity::updateVertexData() {
	sprite.updateVertexData();
}

///////////////////////////////////////////////////////////////////////////////
//OPERATORS
///////////////////////////////////////////////////////////////////////////////
/*Entity& operator=(Entity e) {
	Entity r = Entity()
}*/
