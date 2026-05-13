#pragma once
#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>

enum class Birdtype{Red,Black,Yellow,Blue};

class Bird : public virtual DynamicObject {
private:

public:
	Bird() = default;

	Bird(EntityData& birdData, float birdX, float birdY, float birdRotation, b2World& world) : DynamicObject(birdData, birdX, birdY, birdRotation, world) {};//passed so can use things from dynamic object

};