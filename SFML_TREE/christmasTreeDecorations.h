#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

CircleShape drawBall(float x=0, float y=0, float trunkCenter=0, float trunkHeight=0)
{
	CircleShape ball;
	for (int i = 0; i < 13; i++)
	{
		ball.setRadius((float)(rand() % 15) + 5);
		ball.setPosition(Vector2f((float)(rand() % (int)trunkCenter + x) + (float)trunkCenter - x, (float)(rand()%(int)trunkHeight)+y));
		ball.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
	}

	return ball;
}