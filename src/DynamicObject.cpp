#include "DynamicObject.h"



DynamicObject::DynamicObject(std::string DynConstrutor)
{
	DynTextureLoc = DynConstrutor;

	if (DynTexture.loadFromFile(DynTextureLoc , sf::IntRect(0, 0, 60, 52) )) {
		std::cout << "not loaded" << std::endl;
	}

	DynSprite.setTexture(DynTexture);
	DynSprite.setPosition(sf::Vector2f(200.0f, 200.0f));
}

void DynamicObject::render(sf::RenderWindow& GObjRenderWindow)
{
	GObjRenderWindow.draw(DynSprite);
}

void DynamicObject::update()
{
}



