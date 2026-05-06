#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class Bird : public virtual DynamicObject {
private:

public:
	Bird() = default;

	Bird(std::string BirdLoc, sf::IntRect BirdIntRect, b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution) : DynamicObject(BirdLoc, BirdIntRect, BirdStartPos, World, BirdDensity, BirdFriction, BirdRestitution) {};//passed so can use things from dynamic object
};