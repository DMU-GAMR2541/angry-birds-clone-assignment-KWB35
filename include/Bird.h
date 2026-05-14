#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

enum class Birdtype{Red, Black, Yellow};

class Bird : public virtual DynamicObject {
private:

public:
	Bird()
	{

	};

	Bird(std::string BirdLoc,  b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution, float BirdRadii, float BScaleX, float BScaleY) : DynamicObject(BirdLoc, BirdStartPos, World, BirdDensity, BirdFriction, BirdRestitution, BirdRadii, BScaleX, BScaleY) {};//passed so can use things from dynamic object



};