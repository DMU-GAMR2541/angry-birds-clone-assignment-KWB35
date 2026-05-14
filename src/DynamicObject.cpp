#include "DynamicObject.h"

bool n = true;

DynamicObject::DynamicObject(std::string DynConstrutor,b2Vec2 DynStartPos,b2World &World, float Density, float Friction, float Restitution, float Radius, float ScaleX, float ScaleY, int i_Health, float rotation,std::string shape)
{
	DynTextureLoc = DynConstrutor;

	if (!DynTexture.loadFromFile(DynTextureLoc)) {
		std::cout << "not loaded" << std::endl;
	}
	

	DynSprite.setTexture(DynTexture);
	DynSprite.setPosition(200.0f, 200.0f);
	DynSprite.setScale(ScaleX, ScaleY);
	DynSprite.setRotation(rotation);
	
	
	DynSprite.setOrigin(DynSprite.getLocalBounds().height / 2, DynSprite.getLocalBounds().width / 2); //Sets the origin to the center of the sprite

	b2_dynamicCircle.m_radius = Radius;

	

	b2_bodyDef.type = b2_dynamicBody;
	b2_bodyDef.position = DynStartPos;
	//Create the body in the world
	b2_body = World.CreateBody(&b2_bodyDef);
	
	if (!b2_body)return;

	//setup fixtures
	if (shape == "circle")
	{
		b2_fixtureDef.shape = &b2_dynamicCircle;
	}
	else 
	{
		b2PolygonShape boxShape;
		boxShape.SetAsBox(84.0f / 2.0f / Scale, 10.0f / 2.0f / Scale);

		static b2PolygonShape safeBox;
		safeBox = boxShape;

		b2_fixtureDef.shape = &safeBox;
 
	}
	
	b2_fixtureDef.density = Density;
	b2_fixtureDef.friction = Friction;
	b2_fixtureDef.restitution = Restitution;

	b2_body->CreateFixture(&b2_fixtureDef);
}


void DynamicObject::setBody(b2Body* body) 
{
	b2_body = body;
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
	DynSprite.setPosition(sf::Vector2(b2_body->GetPosition().x * Scale, b2_body->GetPosition().y * Scale));//updates position
	DynSprite.setRotation(b2_body->GetAngle() * 180 / b2_pi);//Update rotation
	
}






