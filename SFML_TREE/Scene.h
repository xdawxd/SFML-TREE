#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "christmasTree.h"
#include "Stars.h"
#include "starShine.h"

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

    ConvexShape starShine;
};

Scene createScene(int width, int height)
{
    Scene rv;

    //------------------------- BACKGROUND -----------------------------//

    rv.background.setFillColor(Color(28, 22, 36)); //47, 41, 99
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

    rv.christmasTree = createChrismasTree(trunkCenter, trunkHeight, &rv.christmasTreeStar);

    rv.starShine = starShine();

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

    win.draw(scene.starShine);
}
/*
void updateScene(Scene& scene)
{

}
*/
