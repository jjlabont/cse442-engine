#pragma once

#include "Util/DataTypes.h"

struct Sprite {
	Sprite() : body(goat::Rect()), color(goat::Color()), texCoords(goat::Rect()), rot(0.0f) {}
	Sprite(goat::Rect body, goat::Color c, goat::Rect texCoords = goat::Rect()) : body(body), color(c), texCoords(texCoords), rot(0.0f) {};

	goat::Rect body;
	goat::Color color;
	goat::Rect texCoords;
	float rot;
};