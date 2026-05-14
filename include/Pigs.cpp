#include <iostream>
#include "Pig.h"


Pig::Pig(std::string PigLoc, b2Vec2 PigStartPos, b2World& World, float PigDensity, float PigFriction, float PigRestitution, float PigRadii, float PScaleX, float PScaleY, int pigHealth, float pigRotation, std::string pigShape, float maxHealth) : DynamicObject(PigLoc, PigStartPos, World, PigDensity, PigFriction, PigRestitution, PigRadii, PScaleX, PScaleY, pigHealth, pigRotation, pigShape) {


	health = maxHealth; //sets the health of the pig to the max value when created
};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 


void Pig::TakeDamage(float damage)
{
	health -= damage;

	if (health <= 0) //if health is less tha or equal to 0 destroyed is set to true
	{
		destroyed = true; 
	}
}