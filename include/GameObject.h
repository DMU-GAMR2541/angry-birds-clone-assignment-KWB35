#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> //if audio is wanted add audio.hpp
#include "box2d/box2d.h"

class GameObject 
{
private:
	sf::Vector2f v2_position; //SFML vector for position
	sf::Sprite sp_sprite; //SFML sprite that is displayed
	bool b_colliding = false; //Check for collision
	std::string str_spriteLoc; //string for the location of the sprite
	sf::Texture tx_texture; //Texture for the sprite to be loaded from

public:
	//Default Constructor
	GameObject() = default;
	//Default destructor
	virtual ~GameObject() = default;
	
	virtual void render(sf::RenderWindow& GObjRenderWindow) = 0;
	virtual void update() = 0; //fully virtual functions

	virtual void TakeDamage(float damage);
	bool destroyed = false;
	float health = 0.0f;

protected:
	const float Scale = 30.0f;
};