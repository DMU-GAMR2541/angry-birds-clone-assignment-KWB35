#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class Bird : public virtual DynamicObject {
private:

public:
	Bird() = default;

	Bird(std::string BirdLoc, sf::IntRect BirdIntRect, sf::Vector2f BirdStartPos, b2World& World) : DynamicObject(BirdLoc, BirdIntRect, BirdStartPos, World) {};//passed so can use things from dynamic object
};