#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

enum class PigSize;

class Pig : public virtual DynamicObject {
private:

protected:
	float const Health = 2;
	
public:
	Pig() = default;

	Pig(std::string PigLoc, b2Vec2 PigStartPos, b2World &World, float PigDensity, float PigFriction, float PigRestitution, float PigRadii) : DynamicObject(PigLoc, PigStartPos, World, PigDensity, PigFriction, PigRestitution, PigRadii) {};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 
};