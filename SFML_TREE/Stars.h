#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

struct StarsStruct
{
	std::vector<Color> Colors();
	std::vector<ConvexShape> createStars1(int numOfStars);
	std::vector<RectangleShape> createStars2(int numOfStars);
};
