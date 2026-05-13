#include "DynamicObject.h"



DynamicObject::DynamicObject(b2World& world, const EntityData& DynData, float DynX, float DynY, float DynRotation)//std::string DynConstrutor,b2Vec2 DynStartPos,b2World &World, float Density, float Friction, float Restitution, float Radius)
{
	

	if (!DynTexture.loadFromFile(DynData.texture)) {
		std::cout << "not loaded" << std::endl;
	}
	
	

	DynSprite.setTexture(DynTexture);
	DynSprite.setPosition(200.0f, 200.0f);
	DynSprite.setScale(0.1,0.1);
	
	DynSprite.setOrigin(DynSprite.getLocalBounds().height / 2, DynSprite.getLocalBounds().width / 2); //Sets the origin to the center of the sprite



	b2_bodyDef.type = b2_dynamicBody;
	b2_bodyDef.position = b2Vec2(DynData.width,DynData.height);
	//Create the body in the world
	b2_body = world.CreateBody(&b2_bodyDef);

	

	b2_body->CreateFixture(&b2_fixtureDef);
}

void DynamicObject::render(sf::RenderWindow& GObjRenderWindow)
{
	GObjRenderWindow.draw(DynSprite);
}

void DynamicObject::update()
{
}

void DynamicObject::UpdateSprite() 
{
	DynSprite.setPosition(sf::Vector2(b2_body->GetPosition().x * Scale, b2_body->GetPosition().y * Scale));
	
}





