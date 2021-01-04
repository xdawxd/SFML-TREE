#pragma once

#include <tuple>
#include "SFML/Graphics.hpp"

using namespace sf;

struct christmasTreeStruct
{
    int width;
    int height;

    ConvexShape christmasTree;
    ConvexShape christmasTreeStar;

    RectangleShape createTrunk(float trunkCenter, float trunkHeight, float trunkW, float trunkH);
    RectangleShape createBark1(float trunkCenter, float trunkHeight, float trunkW, float trunkH);
    RectangleShape createBark2(float trunkCenter, float trunkHeight, float trunkW, float trunkH);
    RectangleShape createBark3(float trunkCenter, float trunkHeight, float trunkW, float trunkH);

    ConvexShape createTree(float trunkCenter, float trunkHeight, float *treeTip);

    ConvexShape createStar(float trunkCenter, float treeTip);

    ConvexShape starShine(float trunkCenter, float treeTip, ConvexShape star);
};
