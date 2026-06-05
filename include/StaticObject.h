#pragma once
#include "GameObject.h"



class StaticObject : public virtual GameObject 
{
private:
	sf::Font font;
	sf::Text text;


public:
	//Default constructor
	StaticObject() = default;
	//Default destructor
	virtual ~StaticObject() = default;

	StaticObject(sf::Vector2f position, std::string text, std::string fontLocation);

	sf::Text getText()
	{
		return text;
	}

	void render(sf::RenderWindow& GObjRenderWindow) override;
	void update() override;
};