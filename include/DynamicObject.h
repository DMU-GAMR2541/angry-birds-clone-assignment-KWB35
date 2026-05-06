#pragma once
#include "GameObject.h"


class DynamicObject : public virtual GameObject
{
private:
	sf::Sprite DynSprite;
	sf::Texture DynTexture;
	std::string DynTextureLoc;
	sf::RenderWindow DynRenderWindow;  

	//Adding physics to the sprites
	b2Vec2 b2_pos; //The position of the object in the game world
	b2BodyDef b2_bodyDef; //The body definition for the object in the Box2D physics engine
	b2FixtureDef b2_fixtureDef; //The fixture definition for the object in the Box2D physics engine
	b2Body* b2_body; //the body for the object in the box2D physics engine
	b2CircleShape b2_dynamicCircle; //The shape of the object in the Box2D physics engine defined as a circle

public:
	//Default constructor
	DynamicObject() = default;
	//Default destructor
	virtual ~DynamicObject() = default;

	//overload constructor
	DynamicObject(std::string DynConstrutor, sf::IntRect DynIntRect, b2Vec2 DynStartPos, b2World &World, float Density, float Friction, float Restitution);

	void render(sf::RenderWindow& GObjRenderWindow) override;
	void update() override;
	void UpdateSprite();


	
};

