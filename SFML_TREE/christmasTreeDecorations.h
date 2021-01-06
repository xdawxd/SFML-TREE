#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

struct Decorations
{
	CircleShape createBauble(float x, float y);
	std::vector<RectangleShape> gift(float positionX, float positionY, Color color);
};
