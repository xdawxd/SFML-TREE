#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

ConvexShape createChristmasTreeStar(float trunkCenter=0, float christmasTreeTip=0)
{
    ConvexShape christmasTreeStar;

    //------------------------- STAR MODEL -----------------------------//

    christmasTreeStar.setPointCount(10);
    christmasTreeStar.setFillColor(Color().Yellow);

    float starW = trunkCenter - 12.0f;
    float starH = christmasTreeTip + 14.0f;

    christmasTreeStar.setPosition(Vector2f(starW, starH));

    christmasTreeStar.setPoint(0, Vector2f(0.f, 0.f));
    christmasTreeStar.setPoint(1, Vector2f(+5.0f, -14.0f));
    christmasTreeStar.setPoint(2, Vector2f(-8.0f, -23.0f));
    christmasTreeStar.setPoint(3, Vector2f(+8.0f, -23.0f));
    christmasTreeStar.setPoint(4, Vector2f(+12.0f, -37.0f));
    christmasTreeStar.setPoint(5, Vector2f(+17.0f, -23.0f));
    christmasTreeStar.setPoint(6, Vector2f(+32.0f, -23.0f));
    christmasTreeStar.setPoint(7, Vector2f(+20.0f, -14.0f));
    christmasTreeStar.setPoint(8, Vector2f(+24.0f, 0.f));
    christmasTreeStar.setPoint(9, Vector2f(+12.0f, -7.0f));

    return christmasTreeStar;
}
