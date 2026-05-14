#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>


class Blocks : public virtual DynamicObject {//inherits from DynamicObject
private:


protected:


public:
	Blocks() = default;

	Blocks(std::string BlockLoc, b2Vec2 BlockStartPos, b2World& World, float BlockDensity, float BlockFriction, float BlockRestitution, float BlockRadii, float BScaleX, float BScaleY, int BlockHealth, float blockRotation, std::string blockShape);

	void update();

	void TakeDamage(float damage) override;
};