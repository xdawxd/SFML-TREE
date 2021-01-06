#pragma once

#include "SFML/Graphics.hpp"
#include "christmasTree.h"
#include "Stars.h"
#include "christmasTreeDecorations.h"

#include <iostream>

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
    // float trunkCenter = 400;
};

Scene createScene(int sWidth, int sHeight)
{
    Scene rv;
    ChristmasTreeStruct cts;

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

    rv.starShine = cts.starShine(trunkCenter, treeTip);

    return rv;
}

void drawScene(RenderWindow& win, const Scene& scene)
{
    win.draw(scene.background);

    int numOfStars = 20;
    int numOfBaubles = 10;
    StarsStruct ss;
    Decorations dec;

    std::vector<ConvexShape> vec1 = ss.createStars1(numOfStars);
    std::vector<RectangleShape> vec2 = ss.createStars2(numOfStars);

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

    Color color1(181, 2, 2);
    Color color2(0, 122, 0);
    Color color3(125, 125, 125);

    std::vector<RectangleShape> gift1 = dec.gift(300, 590, color1);
    std::vector<RectangleShape> gift2 = dec.gift(450, 590, color2);
    std::vector<RectangleShape> gift3 = dec.gift(520, 590, color3);

    for (size_t i = 0; i < gift1.size(); i++)
    {
        win.draw(gift1.at(i));
    }
    for (size_t i = 0; i < gift2.size(); i++)
    {
        win.draw(gift2.at(i));
    }
    for (size_t i = 0; i < gift3.size(); i++)
    {
        win.draw(gift3.at(i));
    }

    win.draw(scene.christmasTree);
    win.draw(scene.christmasTreeStar);
    win.draw(scene.starShine);

    win.draw(dec.createBauble(400, 300));
    win.draw(dec.createBauble(350, 340));
    win.draw(dec.createBauble(400, 370));
    win.draw(dec.createBauble(460, 390));
    win.draw(dec.createBauble(325, 400));
    win.draw(dec.createBauble(430, 430));
    win.draw(dec.createBauble(365, 440));
    win.draw(dec.createBauble(310, 465));
    win.draw(dec.createBauble(490, 480));
    win.draw(dec.createBauble(400, 500));
    win.draw(dec.createBauble(250, 510));
    
}   
/*
void updateScene(Scene& scene)
{
    
}
*/