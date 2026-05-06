#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class Pig : public virtual DynamicObject {
private:
	
public:
	Pig() = default;

	Pig(std::string PigLoc,sf::IntRect PigIntRect, b2Vec2 PigStartPos, b2World &World, float PigDensity, float PigFriction, float PigRestitution) : DynamicObject(PigLoc, PigIntRect, PigStartPos, World, PigDensity, PigFriction, PigRestitution) {};//passed so can use things from dynamic object
};