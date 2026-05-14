#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>



class Bird : public virtual DynamicObject {
private:

public:
	Bird(){};

	Bird(std::string BirdLoc,  b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution, float BirdRadii, float BScaleX, float BScaleY, int birdHealth,float birdRotation,std::string birdShape) : DynamicObject(BirdLoc, BirdStartPos, World, BirdDensity, BirdFriction, BirdRestitution, BirdRadii, BScaleX, BScaleY, birdHealth,birdRotation,birdShape) {};//passed so can use things from dynamic object



};