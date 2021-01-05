#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

struct Decorations
{
	std::vector<Color> Colors();
	CircleShape createBall(float x, float y, int numOfObjects);
	RectangleShape createBox(float x, float y, int numOfObjects);
	CircleShape createEye(float x, float y, int numOfObjects);
};