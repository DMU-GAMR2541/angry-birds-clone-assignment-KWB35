#include "DynamicObject.h"



DynamicObject::DynamicObject(std::string DynConstrutor,sf::IntRect DynIntRect,b2Vec2 DynStartPos,b2World &World, float Density, float Friction, float Restitution, float Radius)
{
	DynTextureLoc = DynConstrutor;

	if (!DynTexture.loadFromFile(DynTextureLoc , DynIntRect)) {
		std::cout << "not loaded" << std::endl;
	}
	
	DynSprite.setTexture(DynTexture);
	DynSprite.setPosition(200.0f, 200.0f);
	DynSprite.setScale(0.75,0.75);
	
	DynSprite.setOrigin(DynSprite.getLocalBounds().height / 2, DynSprite.getLocalBounds().width / 2); //Sets the origin to the center of the sprite

	b2_dynamicCircle.m_radius = Radius;

	b2_bodyDef.type = b2_dynamicBody;
	b2_bodyDef.position = DynStartPos;
	//Create the body in the world
	b2_body = World.CreateBody(&b2_bodyDef);

	//setup fixtures
	b2_fixtureDef.shape = &b2_dynamicCircle;
	b2_fixtureDef.density = Density;
	b2_fixtureDef.friction = Friction;
	b2_fixtureDef.restitution = Restitution;

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





