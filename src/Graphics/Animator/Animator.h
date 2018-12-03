#pragma once
#include <unordered_map>
#include "Objects\Entity\Entity.h"

class Animator {
private:
	std::unordered_map<std::string, Entity*>* entities;
public:
	Animator(std::unordered_map<std::string, Entity*>* entities);
	void animate(float d);
};