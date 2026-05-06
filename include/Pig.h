#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class Pig : public virtual DynamicObject {
private:
	
public:
	Pig() = default;

	Pig(std::string PigLoc,sf::IntRect PigIntRect, sf::Vector2f PigStartPos, b2World &World) : DynamicObject(PigLoc, PigIntRect, PigStartPos, World) {};//passed so can use things from dynamic object
};