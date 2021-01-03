#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "christmasTree.h"
#include "christmasTreeStar.h"
#include "Stars.h"

struct Scene
{
    RectangleShape background;

    RectangleShape ground;
    RectangleShape trunk;

    RectangleShape bark1;
    RectangleShape bark2;
    RectangleShape bark3;

    ConvexShape christmasTree;
    ConvexShape christmasTreeStar;
};

Scene createScene(int width, int height)
{
    Scene rv;

    //------------------------- BACKGROUND -----------------------------//

    rv.background.setFillColor(Color(47, 41, 99));
    rv.background.setSize(Vector2f((float)width, (float)height));

    //------------------------- GROUND MODEL -----------------------------//

    rv.ground.setSize(Vector2f((float)width, 20.f));
    rv.ground.setFillColor(Color(102, 89, 71));
    rv.ground.setPosition(0, (float)height - 20.f);

    //------------------------- TRUNK MODEL -----------------------------//

    float trunkCenter = (float)width / 2;
    float trunkHeight = (float)height - 60;

    float trunkW = 50;
    float trunkH = 60;

    rv.trunk.setSize(Vector2f(trunkW, trunkH));
    rv.trunk.setFillColor(Color(71, 54, 24));
    rv.trunk.setPosition(trunkCenter - 25.f, trunkHeight);

    //------------------------- BARK MODELS -----------------------------//

    rv.bark1.setSize(Vector2f(trunkW - 12.5f, trunkH - 8.0f));
    rv.bark1.setFillColor(Color(54, 41, 18)); // brown
    rv.bark1.setPosition(trunkCenter - 18.75f, trunkHeight);

    rv.bark2.setSize(Vector2f(trunkW - 25.0f, trunkH - 16.0f));
    rv.bark2.setFillColor(Color(45, 34, 15)); // darkChocolate
    rv.bark2.setPosition(trunkCenter - 12.5f, trunkHeight);

    rv.bark3.setSize(Vector2f(trunkW - 37.5f, trunkH - 24.0f));
    rv.bark3.setFillColor(Color(32, 24, 11)); // darkBrown
    rv.bark3.setPosition(trunkCenter - 6.25f, trunkHeight);

    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    rv.christmasTree.setPointCount(19);
    rv.christmasTree.setFillColor(Color(36, 92, 36));

    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    float christmasTreeTip = 0;

    for (int i = 0; i < rv.christmasTree.getPointCount(); i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
                christmasTreeTip = currentHeight - verticalSpread;
            }
            else if (i % 2 != 0)
            {
                currentHeight = currentHeight - verticalSpread;
                treeDiv = treeDiv / 1.49;
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDiv, currentHeight));
            }
            else if (i % 2 == 0)
            {
                treeDec = treeDec - 35;
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDec, currentHeight));
            }
        }
        else if (i > 9)
        {
            if (i % 2 != 0)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDiv, currentHeight));
                currentHeight = currentHeight + verticalSpread;
                treeDiv = treeDiv * 1.49;
            }
            else if (i % 2 == 0)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDec, currentHeight));
                treeDec = treeDec + 35;
            }
        }
    }

    //------------------------- STAR MODEL -----------------------------//

    rv.christmasTreeStar.setPointCount(10);
    rv.christmasTreeStar.setFillColor(Color().Yellow);

    float starW = trunkCenter - 12.0f;
    float starH = christmasTreeTip + 14.0f;

    rv.christmasTreeStar.setPosition(Vector2f(starW, starH));

    rv.christmasTreeStar.setPoint(0, Vector2f(0.f, 0.f));
    rv.christmasTreeStar.setPoint(1, Vector2f(+5.0f, -14.0f));
    rv.christmasTreeStar.setPoint(2, Vector2f(-8.0f, -23.0f));
    rv.christmasTreeStar.setPoint(3, Vector2f(+8.0f, -23.0f));
    rv.christmasTreeStar.setPoint(4, Vector2f(+12.0f, -37.0f));
    rv.christmasTreeStar.setPoint(5, Vector2f(+17.0f, -23.0f));
    rv.christmasTreeStar.setPoint(6, Vector2f(+32.0f, -23.0f));
    rv.christmasTreeStar.setPoint(7, Vector2f(+20.0f, -14.0f));
    rv.christmasTreeStar.setPoint(8, Vector2f(+24.0f, 0.f));
    rv.christmasTreeStar.setPoint(9, Vector2f(+12.0f, -7.0f));

    //------------------------- STARS MODELS -----------------------------//
    /*
    rv.star.setPointCount(12);

    rv.star.setPoint(0, Vector2f(0.f, 0.f));
    rv.star.setPoint(1, Vector2f(0.f, -2.f));
    rv.star.setPoint(2, Vector2f(-2.f, -2.f));
    rv.star.setPoint(3, Vector2f(-2.f, -4.f));
    rv.star.setPoint(4, Vector2f(0.f, -4.f));
    rv.star.setPoint(5, Vector2f(0.f, -6.f));
    rv.star.setPoint(6, Vector2f(2.f, -6.f));
    rv.star.setPoint(7, Vector2f(2.f, -4.f));
    rv.star.setPoint(8, Vector2f(4.f, -4.f));
    rv.star.setPoint(9, Vector2f(4.f, -2.f));
    rv.star.setPoint(10, Vector2f(2.f, -2.f));
    rv.star.setPoint(11, Vector2f(2.f, 0.f));
    */

    return rv;
}

void drawScene(RenderWindow& win, const Scene& scene)
{
    win.draw(scene.background);

    int numOfStars = 20;

    std::vector<ConvexShape> vec1 = createStars1(numOfStars);
    std::vector<RectangleShape> vec2 = createStars2(numOfStars);

    for (int i = 0; i < numOfStars; i++)
    {
        win.draw(vec1.at(i));
        win.draw(vec2.at(i));
    }

    win.draw(scene.ground);
    win.draw(scene.trunk);

    win.draw(scene.bark1);
    win.draw(scene.bark2);
    win.draw(scene.bark3);

    win.draw(scene.christmasTree);
    win.draw(scene.christmasTreeStar);
}
/*
void updateScene(Scene& scene)
{

}
*/
