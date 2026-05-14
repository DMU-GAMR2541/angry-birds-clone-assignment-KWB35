#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>


class Pig : public virtual DynamicObject {
private:
	

protected:
	
	
public:
	Pig() = default;

	Pig(std::string PigLoc, b2Vec2 PigStartPos, b2World &World, float PigDensity, float PigFriction, float PigRestitution, float PigRadii, float PScaleX,float PScaleY, int pigHealth, float pigRotation, std::string pigShape) : DynamicObject(PigLoc, PigStartPos, World, PigDensity, PigFriction, PigRestitution, PigRadii, PScaleX, PScaleY, pigHealth, pigRotation, pigShape) {};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 

	
};