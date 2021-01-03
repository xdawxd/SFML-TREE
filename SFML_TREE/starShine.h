#pragma once

#include "SFML/Graphics.hpp"
#include "christmasTreeStar.h"

using namespace sf;

ConvexShape starShine()
{
	float trunkCenter = 400;
	float christmasTreeTip = 240;

	ConvexShape star = createChristmasTreeStar(trunkCenter, christmasTreeTip);

	Color yellow;
	yellow.r = 255;
	yellow.g = 255;
	yellow.b = 0;
	yellow.a = 64;

	star.setFillColor(yellow);
	star.setOutlineColor(yellow);
	star.setOutlineThickness(3.f);
	
	return star;
}