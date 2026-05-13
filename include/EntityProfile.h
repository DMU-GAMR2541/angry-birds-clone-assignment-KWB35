#pragma once
#include <string>

struct EntityData {
	std::string texture;

	float width;
	float height;
	float weight;
	float friction;
	float restitution;

	bool isCircle;
};