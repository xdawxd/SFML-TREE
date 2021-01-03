#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

std::vector<Color> Colors()
{
	Color mint;
	mint.r = 127;
	mint.g = 255;
	mint.b = 202;
	mint.a = rand() % 256 + 128;

	Color peach;
	peach.r = 255;
	peach.g = 166;
	peach.b = 127;
	peach.a = rand() % 256 + 128;

	Color lightYellow;
	lightYellow.r = 255;
	lightYellow.g = 237;
	lightYellow.b = 175;
	lightYellow.a = rand() % 256 + 128;

	std::vector<Color> colors = {mint, peach, lightYellow};

	return colors;
}

std::vector<ConvexShape> createStars1(int numOfStars)
{
	std::vector<Color> colors = Colors();

	ConvexShape star;

	star.setPointCount(12);

	star.setPoint(0, Vector2f(0.f, 0.f));
	star.setPoint(1, Vector2f(0.f, -2.f));
	star.setPoint(2, Vector2f(-2.f, -2.f));
	star.setPoint(3, Vector2f(-2.f, -4.f));
	star.setPoint(4, Vector2f(0.f, -4.f));
	star.setPoint(5, Vector2f(0.f, -6.f));
	star.setPoint(6, Vector2f(2.f, -6.f));
	star.setPoint(7, Vector2f(2.f, -4.f));
	star.setPoint(8, Vector2f(4.f, -4.f));
	star.setPoint(9, Vector2f(4.f, -2.f));
	star.setPoint(10, Vector2f(2.f, -2.f));
	star.setPoint(11, Vector2f(2.f, 0.f));

	std::vector<ConvexShape> stars;

	for (int i = 0; i < numOfStars; i++) {
		star.setPosition(Vector2f(rand()%800, rand()%600));
		star.setFillColor(colors[rand()%3]);
		stars.push_back(star);
	}
	return stars;
}

std::vector<RectangleShape> createStars2(int numOfStars)
{
	std::vector<Color> colors = Colors();

	std::vector<RectangleShape> stars;

	int starSize = 0;

	for (int i = 0; i < numOfStars; i++)
	{
		RectangleShape starDot;

		starSize = (rand() % 4) + 1;

		starDot.setSize(Vector2f((float)starSize, (float)starSize));
		starDot.setPosition(Vector2f(rand() % 800, rand() % 600));
		starDot.setFillColor(colors[rand() % 3]);

		stars.push_back(starDot);
	}

	return stars;
}