#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>


class Blocks : public virtual DynamicObject {
private:


protected:


public:
	Blocks() = default;

	Blocks(std::string BlockLoc, b2Vec2 BlockStartPos, b2World& World, float BlockDensity, float BlockFriction, float BlockRestitution, float BlockRadii, float BScaleX, float BScaleY, int BlockHealth, float blockRotation, std::string blockShape) : DynamicObject(BlockLoc, BlockStartPos, World, BlockDensity, BlockFriction, BlockRestitution, BlockRadii, BScaleX, BScaleY, BlockHealth, blockRotation, blockShape) {};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 


};