#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

enum class PigSize;

class Pig : public virtual DynamicObject {
private:
	int i_Health;

protected:

	
public:
	Pig() = default;

	Pig(std::string PigLoc, b2Vec2 PigStartPos, b2World &World, float PigDensity, float PigFriction, float PigRestitution, float PigRadii, float PScaleX,float PScaleY) : DynamicObject(PigLoc, PigStartPos, World, PigDensity, PigFriction, PigRestitution, PigRadii, PScaleX, PScaleY) {};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 

};