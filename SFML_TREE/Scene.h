#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "christmasTree.h"
#include "Stars.h"
#include "christmasTreeDecorations.h"

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
    CircleShape ball; // 13
};

Scene createScene(int sWidth, int sHeight)
{
    Scene rv;
    christmasTreeStruct cts;

    cts.width = sWidth;
    cts.width = sHeight;
    float trunkCenter = (float)sWidth / 2;
    float trunkHeight = (float)sHeight - 60;
    float trunkW = 50;
    float trunkH = 60;
    float treeTip = 0;


    //------------------------- BACKGROUND -----------------------------//

    rv.background.setFillColor(Color(28, 22, 36)); //47, 41, 99
    rv.background.setSize(Vector2f((float)sWidth, (float)sHeight));

    //------------------------- GROUND MODEL -----------------------------//

    rv.ground.setSize(Vector2f((float)sWidth, 20.f));
    rv.ground.setFillColor(Color(102, 89, 71));
    rv.ground.setPosition(0, (float)sHeight - 20.f);

    //------------------------- TRUNK MODEL -----------------------------//
    
    rv.trunk = cts.createTrunk(trunkCenter, trunkHeight, trunkW, trunkH);

    //------------------------- BARK MODELS -----------------------------//

    rv.bark1 = cts.createBark1(trunkCenter, trunkHeight, trunkW, trunkH);
    rv.bark2 = cts.createBark2(trunkCenter, trunkHeight, trunkW, trunkH);
    rv.bark3 = cts.createBark3(trunkCenter, trunkHeight, trunkW, trunkH);

    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    rv.christmasTree = cts.createTree(trunkCenter, trunkHeight, &treeTip);

    //------------------------- STAR MODEL -----------------------------//

    rv.christmasTreeStar = cts.createStar(trunkCenter, treeTip);

    //------------------------- SHINING STAR MODEL -----------------------------//

    rv.starShine = cts.starShine(trunkCenter, treeTip, rv.christmasTreeStar);

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
    /*
    std::vector<CircleShape> balls(13, scene.ball);

    for (size_t i = 0; i < balls.size(); i++)
    {
        win.draw(balls.at(i));
    }
    */
}
/*
void updateScene(Scene& scene)
{

}
*/
