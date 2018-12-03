#include "Animator.h"

Animator::Animator(std::unordered_map<std::string, Entity*>* entities) : 
	entities(entities) {
}

void Animator::animate(float d) {
	for (std::pair<std::string, Entity*> ePair : *entities) {
		Entity* e = ePair.second;
		e->animateWithDelta(d);
		std::cout << e->getTexCoordsW() << std::endl;

	}
}