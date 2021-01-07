#pragma once

#include "Stars.h"
#include "christmasTree.h"
#include "christmasTreeDecorations.h"

struct Scene
{
    RectangleShape background;
    std::vector<CircleShape> snowParticles;
    std::vector<ConvexShape> stars1;
    std::vector<RectangleShape> stars2;

    RectangleShape snow;
    RectangleShape ground;

    RectangleShape trunk;
    RectangleShape bark1;
    RectangleShape bark2;
    RectangleShape bark3;

    ConvexShape christmasTree;
    ConvexShape christmasTreeStar;

    CircleShape bauble1;
    CircleShape bauble2;
    CircleShape bauble3;
    CircleShape bauble4;
    CircleShape bauble5;
    CircleShape bauble6;
    CircleShape bauble7;
    CircleShape bauble8;
    CircleShape bauble9;
    CircleShape bauble10;
    CircleShape bauble11;

    std::vector<RectangleShape> gift1;
    std::vector<RectangleShape> gift2;
    std::vector<RectangleShape> gift3;
    std::vector<RectangleShape> gift4;

    float trunkCenter = 400;
    float trunkHeight = 540;
    float trunkW = 50;
    float trunkH = 60;
    float treeTip = 0;

    int numOfStars = 40;
    int numOfSnowParticles = 300;

    Clock clock;
};

Scene createScene(int sWidth, int sHeight)
{
    Scene sc;
    StarsStruct ss;
    ChristmasTreeStruct cts;
    Decorations dec;

    //------------------------- BACKGROUND -----------------------------//

    sc.background.setFillColor(Color(28, 22, 36)); //47, 41, 99
    sc.background.setSize(Vector2f((float)sWidth, (float)sHeight));

    //------------------------- SNOWFLAKES -----------------------------//

    for (int i = 0; i < sc.numOfSnowParticles; i++)
    {
        CircleShape snowBall;
        snowBall.setRadius((float)(rand() % 2) + 1);
        snowBall.setPosition((float)(rand() % sWidth), (float)(rand() % sHeight));
        snowBall.setFillColor(Color(255, 255, 255, rand() % 255 + 160));

        sc.snowParticles.push_back(snowBall);
    }

    //------------------------- STARS -----------------------------//

    sc.stars1 = ss.createStars1(sc.numOfStars);
    sc.stars2 = ss.createStars2(sc.numOfStars);

    //------------------------- GROUND -----------------------------//

    sc.ground.setSize(Vector2f((float)sWidth, 20.f));
    sc.ground.setFillColor(Color(102, 89, 71));
    sc.ground.setPosition(0, (float)sHeight - 20.f);

    sc.snow.setSize(Vector2f((float)sWidth, 15.f));
    sc.snow.setFillColor(Color().White);
    sc.snow.setPosition(0, (float)sHeight - 20.f);

    //------------------------- TRUNK -----------------------------//

    sc.trunk = cts.createTrunk(sc.trunkCenter, sc.trunkHeight, sc.trunkW, sc.trunkH);
    sc.bark1 = cts.createBark1(sc.trunkCenter, sc.trunkHeight, sc.trunkW, sc.trunkH);
    sc.bark2 = cts.createBark2(sc.trunkCenter, sc.trunkHeight, sc.trunkW, sc.trunkH);
    sc.bark3 = cts.createBark3(sc.trunkCenter, sc.trunkHeight, sc.trunkW, sc.trunkH);

    //------------------------- GIFT -----------------------------//

    sc.gift1 = dec.gift(230, 589, Color(125, 125, 125));
    sc.gift2 = dec.gift(300, 592, Color(181, 2, 2));
    sc.gift3 = dec.gift(450, 590, Color(0, 122, 0));
    sc.gift4 = dec.gift(520, 594, Color(25, 125, 125));

    //------------------------- CHRISTMAS TREE -----------------------------//

    sc.christmasTree = cts.createTree(sc.trunkCenter, sc.trunkHeight, &sc.treeTip);
    sc.christmasTreeStar = cts.createStar(sc.trunkCenter, sc.treeTip);

    //------------------------- BAUBLE -----------------------------//

    sc.bauble1 = dec.createBauble(400, 300);
    sc.bauble2 = dec.createBauble(350, 340);
    sc.bauble3 = dec.createBauble(400, 370);
    sc.bauble4 = dec.createBauble(460, 390);
    sc.bauble5 = dec.createBauble(325, 400);
    sc.bauble6 = dec.createBauble(430, 430);
    sc.bauble7 = dec.createBauble(365, 440);
    sc.bauble8 = dec.createBauble(310, 465);
    sc.bauble9 = dec.createBauble(490, 480);
    sc.bauble10 = dec.createBauble(400, 500);
    sc.bauble11 = dec.createBauble(250, 510);

    return sc;
};

void drawScene(RenderWindow& win, Scene &scene)
{
    win.draw(scene.background);

    for (size_t i = 0; i < scene.snowParticles.size(); i++)
    {
        win.draw(scene.snowParticles.at(i));
    }

    for (int i = 0; i < scene.numOfStars; i++)
    {
        win.draw(scene.stars1.at(i));
        win.draw(scene.stars2.at(i));
    }

    win.draw(scene.ground);
    win.draw(scene.snow);

    win.draw(scene.trunk);
    win.draw(scene.bark1);
    win.draw(scene.bark2);
    win.draw(scene.bark3);

    for (size_t i = 0; i < 3; i++)
    {
        win.draw(scene.gift1.at(i));
        win.draw(scene.gift2.at(i));
        win.draw(scene.gift3.at(i));
        win.draw(scene.gift4.at(i));
    }

    win.draw(scene.christmasTree);
    win.draw(scene.christmasTreeStar);

    win.draw(scene.bauble1);
    win.draw(scene.bauble2);
    win.draw(scene.bauble3);
    win.draw(scene.bauble4);
    win.draw(scene.bauble5);
    win.draw(scene.bauble6);
    win.draw(scene.bauble7);
    win.draw(scene.bauble8);
    win.draw(scene.bauble9);
    win.draw(scene.bauble10);
    win.draw(scene.bauble11);
}   

void updateScene(Scene &scene)
{
    for (size_t i = 0; i < scene.snowParticles.size(); i++)
    {
        float getX = scene.snowParticles.at(i).getPosition().x;
        float getY = scene.snowParticles.at(i).getPosition().y;

        scene.snowParticles.at(i).setPosition(getX + (rand()%2)-0.5, getY + rand()%2);

        if (scene.snowParticles.at(i).getPosition().y > 580)
        {
            scene.snowParticles.at(i).setPosition(getX, 0);
        }
    }
}
