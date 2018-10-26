#pragma once
#include <tuple>
#include <string>
#include "Graphics/Graphics.h"
#include "Input/Input.h"

class Entity {
private:
	std::string name;

	Sprite sprite;
	goat::vec2 speed;

public:

	Entity(std::string name, Sprite sprite);
	~Entity();

	//implementable functions
	virtual void update() {};

	std::string getName() const;
	//position
	void setX(float x);
	float getX() const;
	void setY(float y);
	float getY() const;
	void setW(float w);
	float getW() const;
	void setH(float h);
	float getH() const;
	//rotation
	void setRotX(float x);
	float getRotX() const;
	void setRotY(float x);
	float getRotY() const;
	void setRotZ(float x);
	float getRotZ() const;
	//texcoords
	void setTexCoordsX(float x);
	float getTexCoordsX() const;
	void setTexCoordsY(float y);
	float getTexCoordsY() const;
	void setTexCoordsW(float w);
	float getTexCoordsW() const;
	void setTexCoordsH(float h);
	float getTexCoordsH() const;

	//movement
	void setSpeed(goat::vec2 speed);
	goat::vec2 getSpeed() const;
};