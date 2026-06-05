#include "StaticObject.h"

void StaticObject::render(sf::RenderWindow& GObjRenderWindow)
{
	GObjRenderWindow.draw(text);
}

void StaticObject::update() 
{
}

StaticObject::StaticObject(sf::Vector2f position, std::string UItext, std::string fontLoc)
{
	if (!font.loadFromFile(fontLoc))
	{
		std::cout << "Error loading font" << std::endl;
	}
	else 
	{
		text.setFont(font);
		text.setString(UItext);
		text.setPosition(position);

	}
}