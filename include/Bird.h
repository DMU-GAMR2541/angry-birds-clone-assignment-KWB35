#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>



class Bird : public virtual DynamicObject {
private:

public:
	Bird(){};

	Bird(std::string BirdLoc, b2Vec2 BirdStartPos, b2World& World, float BirdDensity, float BirdFriction, float BirdRestitution, float BirdRadii, float BScaleX, float BScaleY, int birdHealth, float birdRotation, std::string birdShape);

	void load();
	void fire(b2Vec2 impulse);
	b2Body* getBody();

	void TakeDamage(float damage) override;

	bool loaded = true;
	bool fired = false;




};