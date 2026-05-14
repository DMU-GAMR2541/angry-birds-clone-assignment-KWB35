#include "Blocks.h"
#include <iostream>

Blocks::Blocks(std::string BlockLoc, b2Vec2 BlockStartPos, b2World& World, float BlockDensity, float BlockFriction, float BlockRestitution, float BlockRadii, float BScaleX, float BScaleY, int BlockHealth, float blockRotation, std::string blockShape) : DynamicObject(BlockLoc, BlockStartPos, World, BlockDensity, BlockFriction, BlockRestitution, BlockRadii, BScaleX, BScaleY, BlockHealth, blockRotation, blockShape) {
	
	b2_body->SetTransform(b2_body->GetPosition(), 0);

};//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 


void Blocks::TakeDamage(float damage)
{
	health -= damage;
	std::cout << "blocks took damage:" << damage << std::endl;

	if (health <= 0)
	{
		std::cout << "block destroyed" << std::endl;
		destroyed = true;
	}
}