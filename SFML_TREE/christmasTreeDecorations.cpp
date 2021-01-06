#include "christmasTreeDecorations.h"

CircleShape Decorations::createBauble(float x, float y)
{
    CircleShape ball;

    int colorR = rand() % 255;
    int colorG = rand() % 255;
    int colorB = rand() % 255;
    int colorA = 96;

    ball.setRadius(10.f);
    ball.setPosition(x, y);
    ball.setFillColor(Color(colorR, colorG, colorB));

    ball.setOutlineColor(Color(colorR, colorG, colorB, colorA));
    ball.setOutlineThickness(3.f);

    return ball;
}

std::vector<RectangleShape> Decorations::gift(float positionX, float positionY, Color color) // 300, 580
{

    float sizeX = 55;
    float sizeY = 55;

    RectangleShape box1;
    RectangleShape box2;
    RectangleShape box3;

    box1.setSize(Vector2f(sizeX, sizeY));
    box1.setFillColor(color);
    box1.setPosition(positionX, positionY - sizeY);
    box1.setOutlineColor(Color(211, 175, 55));
    box1.setOutlineThickness(1.f);

    box2.setSize(Vector2f(sizeX, sizeY / 4));
    box2.setFillColor(Color(211, 175, 55));
    box2.setPosition(positionX, (positionY - sizeY) + (sizeY / 2.5));

    box3.setSize(Vector2f(sizeX / 4, sizeY));
    box3.setFillColor(Color(211, 175, 55));
    box3.setPosition(positionX + (sizeX / 2.5), positionY - sizeY);

    std::vector<RectangleShape> giftElements = { box1, box2, box3 };

    return giftElements;
}