#include "Stars.h"

std::vector<Color> StarsStruct::Colors()
{
	Color azure;
	azure.r = 89;
	azure.g = 184;
	azure.b = 235;
	azure.a = rand() % 256 + 192;

	Color lightYellow;
	lightYellow.r = 244;
	lightYellow.g = 224;
	lightYellow.b = 112;
	lightYellow.a = 255;

	std::vector<Color> colors = { azure, lightYellow };

	return colors;
}

std::vector<ConvexShape> StarsStruct::createStars1(int numOfStars)
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
		star.setPosition(Vector2f(rand() % 800, rand() % 600));
		star.setFillColor(colors[rand() % 2]);
		stars.push_back(star);
	}
	return stars;
}

std::vector<RectangleShape> StarsStruct::createStars2(int numOfStars)
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
		starDot.setFillColor(colors[rand() % 2]);

		stars.push_back(starDot);
	}
	return stars;
}
