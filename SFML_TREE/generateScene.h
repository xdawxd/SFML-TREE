#pragma once

#include "Stars.h"
#include "christmasTree.h"
#include "christmasTreeDecorations.h"

struct Scene
{
    RectangleShape background;
    RectangleShape snow;
    RectangleShape ground;
    std::vector<CircleShape> snowParticles;

    std::vector<ConvexShape> stars1;
    std::vector<RectangleShape> stars2;
    
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

    float trunkCenter = 400;
    float trunkHeight = 540;
    float trunkW = 50;
    float trunkH = 60;
    float treeTip = 0;

    int numOfStars = 40;
    int numOfSnowParticles = 150;
};

Scene createScene(int sWidth, int sHeight)
{
    Scene sc;
    StarsStruct ss;
    Decorations dec;

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

    //------------------------- SNOWFLAKES MODEL -----------------------------//

    for (int i = 0; i < sc.numOfSnowParticles; i++)
    {
        CircleShape snowBall;
        snowBall.setRadius((float)(rand() % 2) + 1);
        snowBall.setPosition((float)(rand()%sWidth), (float)(rand()%sHeight));
        snowBall.setFillColor(Color(255, 255, 255, rand()%255+160));

        sc.snowParticles.push_back(snowBall);
    }

    //------------------------- BAUBLE MODELS -----------------------------//

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

    sc.stars1 = ss.createStars1(sc.numOfStars);
    sc.stars2 = ss.createStars2(sc.numOfStars);

    return sc;
};

void drawScene(RenderWindow& win, Scene &scene)
{
    win.draw(scene.background);

    for (size_t i = 0; i < scene.snowParticles.size(); i++)
    {
        win.draw(scene.snowParticles.at(i));
    }

    Color color1(181, 2, 2);
    Color color2(0, 122, 0);
    Color color3(125, 125, 125);

    ChristmasTreeStruct cts;
    Decorations dec;

    std::vector<RectangleShape> gift1 = dec.gift(300, 590, color1);
    std::vector<RectangleShape> gift2 = dec.gift(450, 590, color2);
    std::vector<RectangleShape> gift3 = dec.gift(520, 590, color3);

    for (int i = 0; i < scene.numOfStars; i++)
    {
        win.draw(scene.stars1.at(i));
        win.draw(scene.stars2.at(i));
    }

    win.draw(scene.ground);
    win.draw(scene.snow);

    win.draw(cts.createTrunk(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark1(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark2(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));
    win.draw(cts.createBark3(scene.trunkCenter, scene.trunkHeight, scene.trunkW, scene.trunkH));

    for (size_t i = 0; i < 3; i++)
    {
        win.draw(gift1.at(i));
        win.draw(gift2.at(i));
        win.draw(gift3.at(i));
    }

    win.draw(cts.createTree(scene.trunkCenter, scene.trunkHeight, &scene.treeTip));
    win.draw(cts.createStar(scene.trunkCenter, scene.treeTip));

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

        scene.snowParticles.at(i).setPosition(getX, getY + 1);

        if (scene.snowParticles.at(i).getPosition().y > 580)
        {
            scene.snowParticles.at(i).setPosition(getX, 0);
        }
    }
}
