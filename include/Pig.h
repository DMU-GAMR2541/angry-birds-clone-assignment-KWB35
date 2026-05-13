#pragma once
#include "DynamicObject.h"
#include <SFML/Graphics.hpp>
#include "PigProfile.h"
#include<string>


enum class PigSize {Small, Med, Large};

class Pig : public virtual DynamicObject {
private:
	int getInitialHealth(PigSize size) const;
	int i_Health;
	PigSize pigSize;

 	bool destroyed = false;
protected:

	
public:
	Pig() = default;
	virtual ~Pig() = default;

	void update() override;
	void render(sf::RenderWindow& window);

	void takeDamage(int damage);
	bool isDead() const;
	int getHealth() const;
	PigSize getSize();

	Pig(b2World& world, PigSize pigData, float pigX, float pigY, float pigRotation = 0.0f);//passed so can use things from dynamic object //Holds variable that control the spawned pigs key info 
	

};