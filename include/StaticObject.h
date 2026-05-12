#pragma once
#include "GameObject.h"



class StaticObject : public virtual GameObject 
{
private:


public:
	//Default constructor
	StaticObject() = default;
	//Default destructor
	virtual ~StaticObject() = default;

	void render(sf::RenderWindow& GObjRenderWindow) override;
	void update() override;
};