#include "DynamicObject.h"
#include "Bird.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Bird::Bird(std::string BirdLoc, b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution, float BirdRadii, float BScaleX, float BScaleY, int birdHealth, float birdRotation,std::string birdShape) : DynamicObject(BirdLoc, BirdStartPos, World, BirdDensity, BirdFriction, BirdRestitution, BirdRadii, BScaleX, BScaleY, birdHealth, birdRotation, birdShape) {
	
};//passed so can use things from dynamic object



void Bird::TakeDamage(float damage)
{
	std::cout << "Bird took damage:" << damage << std::endl;
}

b2Body* Bird::getBody()
{
	return b2_body;
};