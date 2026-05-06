#include "DynamicObject.h"



DynamicObject::DynamicObject(std::string DynConstrutor,b2World &World)
{
	DynTextureLoc = DynConstrutor;

	if (!DynTexture.loadFromFile(DynTextureLoc , sf::IntRect(0, 0, 60, 52) )) {
		std::cout << "not loaded" << std::endl;
	}

	DynSprite.setTexture(DynTexture);
	DynSprite.setPosition(sf::Vector2f(200.0f, 200.0f));
	

	b2_dynamicCircle.m_radius = 0.5;

	b2_bodyDef.type = b2_dynamicBody;
	b2_bodyDef.position = b2Vec2(200.0f / Scale, 200.0f /Scale);
	//Create the body in the world
	b2_body = World.CreateBody(&b2_bodyDef);

	//setup fixtures
	b2_fixtureDef.shape = &b2_dynamicCircle;
	b2_fixtureDef.density = 1.0f;
	b2_fixtureDef.friction = 0.3f;
	b2_fixtureDef.restitution = 0.5f;  

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



