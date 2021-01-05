#include "christmasTreeDecorations.h"

std::vector<Color> Decorations::Colors()
{
    Color gold;
    gold.r = 255;
    gold.g = 213;
    gold.b = 0;

    Color silver;
    silver.r = 192;
    silver.g = 192;
    silver.b = 192;

    std::vector<Color> colors = { gold, silver };
    return colors;
}

// CREATE THEESE THE SAME AS STARS ON THE SKY


CircleShape Decorations::createBall(float x, float y, int numOfBalls)
{
    CircleShape ball;

    ball.setRadius((float)(rand() % 15) + 5);
    ball.setPosition(x, y);
    ball.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));

    return ball;
}

RectangleShape Decorations::createBox(float x, float y, int numOfObjects)
{
    std::vector<Color> colors = Colors();
    RectangleShape box;

    box.setSize(Vector2f(10.f, 5.f));
    box.setPosition(x, y);
    box.setFillColor(Color(colors[rand() % 2]));

    return box;
}

CircleShape Decorations::createEye(float x, float y, int numOfObjects)
{
    std::vector<Color> colors = Colors();
    CircleShape eye;

    eye.setRadius((float)(rand() % 10) + 5);
    eye.setPosition(x, y);
    eye.setFillColor(Color(colors[rand() % 2]));

    return eye;
}
