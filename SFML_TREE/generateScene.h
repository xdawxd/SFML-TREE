#pragma once

#include "Stars.h"
#include "christmasTree.h"
#include "christmasTreeDecorations.h"

struct Scene
{
    RectangleShape background;
    RectangleShape snow;
    RectangleShape ground;
    
    float trunkCenter = 400;
    float trunkHeight = 540;
    float trunkW = 50;
    float trunkH = 60;
    float treeTip = 0;
};

Scene createScene(int sWidth, int sHeight)
{
    Scene sc;

    //------------------------- BACKGROUND -----------------------------//

    sc.background.setFillColor(Color(28, 22, 36)); //47, 41, 99
    sc.background.setSize(Vector2f((float)sWidth, (float)sHeight));

    //------------------------- GROUND MODEL -----------------------------//

    sc.ground.setSize(Vector2f((float)sWidth, 20.f));
    sc.ground.setFillColor(Color(102, 89, 71));
    sc.ground.setPosition(0, (float)sHeight - 20.f);

    sc.snow.setSize(Vector2f((float)sWidth, 15.f));
    sc.snow.setFillColor(Color().White);
    sc.snow.setPosition(0, (float)sHeight - 20.f);

    return sc;
};

void drawScene(RenderWindow& win, Scene scene)
{
    win.draw(scene.background);

    Color color1(181, 2, 2);
    Color color2(0, 122, 0);
    Color color3(125, 125, 125);

    int numOfStars = 20;
    int numOfBaubles = 10;

    StarsStruct ss;
    ChristmasTreeStruct cts;
    Decorations dec;

    std::vector<ConvexShape> vec1 = ss.createStars1(numOfStars);
    std::vector<RectangleShape> vec2 = ss.createStars2(numOfStars);

    std::vector<RectangleShape> gift1 = dec.gift(300, 590, color1);
    std::vector<RectangleShape> gift2 = dec.gift(450, 590, color2);
    std::vector<RectangleShape> gift3 = dec.gift(520, 590, color3);

    for (int i = 0; i < numOfStars; i++)
    {
        win.draw(vec1.at(i));
        win.draw(vec2.at(i));
    }

    win.draw(scene.ground);
    win.draw(scene.snow);

    win.draw(cts.createTrunk(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark1(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark2(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark3(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));

    for (size_t i = 0; i < gift1.size(); i++)
    {
        win.draw(gift1.at(i));
        win.draw(gift2.at(i));
        win.draw(gift3.at(i));
    }

    win.draw(cts.createTree(scene.trunkCenter, scene.trunkHeight, &scene.treeTip));
    win.draw(cts.createStar(scene.trunkCenter, scene.treeTip));

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
