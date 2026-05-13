#include "Pig.h"
#include "PigProfile.h"

Pig::Pig(PigSize size, float posX, float posY, float rotation, b2World& world) : DynamicObject(getPigProfile(size), posX, posY, rotation, world),
pigSize(size), i_Health(getInitialHealth(size))
{
}

void Pig::update() 
{
	DynamicObject::update();
}

void Pig::render(sf::RenderWindow& window)
{
	DynamicObject::render(window);
}

int Pig::getInitialHealth(PigSize size) const
{
	switch(size)
	{
		case PigSize::Small: return 50;
		case PigSize::Med: return 100;
		case PigSize::Large: return 150;
	}
	return 100;
}

void Pig::takeDamage(int Damage) 
{
	i_Health -= Damage;

	if (i_Health < 0.0f) 
		i_Health = 0;
	std::cout << "Hp lost - Pig" << std::endl;
	
}

bool Pig::isDead() const 
{
	return i_Health;
}
