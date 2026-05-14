#include "DynamicObject.h"
#include "Bird.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Bird::Bird(std::string BirdLoc, b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution, float BirdRadii, float BScaleX, float BScaleY, int birdHealth, float birdRotation,std::string birdShape) : DynamicObject(BirdLoc, BirdStartPos, World, BirdDensity, BirdFriction, BirdRestitution, BirdRadii, BScaleX, BScaleY, birdHealth, birdRotation, birdShape) {
	load();
};//passed so can use things from dynamic object

void Bird::load()
{
	b2_body->SetGravityScale(0.0f);
	b2_body->SetLinearVelocity({ 0, 0 });
	b2_body->SetAngularVelocity(0);
	b2_body->SetAwake(false);
	loaded = true;
	fired = false;
}

void Bird::fire(b2Vec2 impulse)
{
	b2_body->SetGravityScale(1.0f);
	b2_body->SetAwake(true);
	b2_body->ApplyLinearImpulseToCenter(impulse, true);

	loaded = false;
	fired = true;
}

void Bird::TakeDamage(float damage)
{
	std::cout << "Bird took damage:" << damage << std::endl;
}

b2Body* Bird::getBody()
{
	return b2_body;
};