#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

class Pig : public virtual DynamicObject {
private:
	
public:
	Pig() = default;

	Pig(std::string PigLoc, b2World &World) : DynamicObject(PigLoc, World) {};//passed so can use things from dynamic object
};