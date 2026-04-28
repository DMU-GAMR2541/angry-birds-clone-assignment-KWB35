#pragma once
#include "GameObject.h"


class DynamicObject : public virtual GameObject
{
private:
	sf::Sprite DynSprite;
	sf::Texture DynTexture;
	std::string DynTextureLoc;
	sf::RenderWindow DynRenderWindow;
public:
	//Default constructor
	DynamicObject() = default;
	//Default destructor
	virtual ~DynamicObject() = default;

	//overload constructor
	DynamicObject(std::string DynConstrutor);

	void render(sf::RenderWindow& GObjRenderWindow) override;
	void update() override;
};

