#include "ContactListener.h"
#include "Pig.h"
#include "Bird.h"
#include "Blocks.h"
#include <iostream>
#include <cmath>

static GameObject* GetObject(b2Body* b2_body)
{
	//Gets the pointer for gameobject from the b2Bodys user data
	return reinterpret_cast<GameObject*>(b2_body->GetUserData().pointer);
}

void ContactListener::BeginContact(b2Contact* contact)
{
	auto* objA = reinterpret_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);

	auto* objB = reinterpret_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	if (!objA || !objB) return;

	float damage = 1.0f;

	objA->TakeDamage(damage);
	objB->TakeDamage(damage);


}
