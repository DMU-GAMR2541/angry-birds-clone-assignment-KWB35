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
	b2CircleShape b2_dynamicCircle; //The shape of the object in the Box2D physics engine defined as a circle

public:
	//Default constructor
	DynamicObject() = default;
	//Default destructor
	virtual ~DynamicObject() = default;

	//overload constructor
	DynamicObject(std::string DynConstrutor, b2Vec2 DynStartPos, b2World &World, float Density, float Friction, float Restitution, float Radius, float ScaleX, float ScaleY);

	void render(sf::RenderWindow& GObjRenderWindow) override;
	void update() override;
	void UpdateSprite();

	void impulse(b2Vec2 b2_impulse, bool awake) 
	{
		b2_body->ApplyLinearImpulseToCenter(b2_impulse, awake); //Adds impulse to an object
	}

	void setPosition(b2Vec2 ResetPos,float Angle) { b2_body->SetTransform(ResetPos, Angle); }; //allows for an objects position to be reset 
	void setVelocity(b2Vec2 ResetVel) { b2_body->SetLinearVelocity(ResetVel); };//allows for an objects velocity to be reset
	void getPosition() { b2_body->GetPosition(); };

	b2Body* getBody() {return b2_body;};

protected:
	b2Body* b2_body; //the body for the object in the box2D physics engine
};

