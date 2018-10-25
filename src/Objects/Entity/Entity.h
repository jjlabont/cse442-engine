#pragma once
#include <tuple>
#include "Graphics/Graphics.h"
#include "Input/Input.h"

class Entity {
private:
	Sprite sprite;
	goat::vec2 speed;

public:

	Entity(Sprite sprite);
	~Entity();

	//implementable functions
	virtual void update() {};

	//position
	void setX(float x);
	float getX() const;
	void setY(float y);
	float getY() const;
	void setW(float w);
	float getW() const;
	void setH(float h);
	float getH() const;
	void setRot(float r);
	float getRot() const;

	//movement
	void setSpeed(goat::vec2 speed);
	goat::vec2 getSpeed() const;
};