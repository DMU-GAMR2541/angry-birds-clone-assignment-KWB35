#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>


class Pig : public virtual DynamicObject {//inherits from DynamicObject
private:
	

protected:
	
	
public:
	Pig() = default;

	Pig(std::string PigLoc, b2Vec2 PigStartPos, b2World &World, float PigDensity, float PigFriction, float PigRestitution, float PigRadii, float PScaleX,float PScaleY, int pigHealth, float pigRotation, std::string pigShape);

	void TakeDamage(float damage) override; //lowers pig health by damage

	
};