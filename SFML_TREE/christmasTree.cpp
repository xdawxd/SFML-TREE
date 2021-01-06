#include "christmasTree.h"

RectangleShape ChristmasTreeStruct::createTrunk(float trunkCenter, float trunkHeight, float trunkW, float trunkH)
{
    //------------------------- TRUNK MODEL -----------------------------//

    RectangleShape trunk;

    trunk.setSize(Vector2f(trunkW, trunkH));
    trunk.setFillColor(Color(71, 54, 24));
    trunk.setPosition(trunkCenter - 25.f, trunkHeight);

    return trunk;
}

RectangleShape ChristmasTreeStruct::createBark1(float trunkCenter, float trunkHeight, float trunkW, float trunkH)
{
    //------------------------- BARK MODELS -----------------------------//

    RectangleShape bark;

    bark.setSize(Vector2f(trunkW - 12.5f, trunkH - 8.0f));
    bark.setFillColor(Color(54, 41, 18)); // brown
    bark.setPosition(trunkCenter - 18.75f, trunkHeight);

    return bark;
}

RectangleShape ChristmasTreeStruct::createBark2(float trunkCenter, float trunkHeight, float trunkW, float trunkH)
{
    RectangleShape bark;

    bark.setSize(Vector2f(trunkW - 25.0f, trunkH - 16.0f));
    bark.setFillColor(Color(45, 34, 15)); // darkChocolate
    bark.setPosition(trunkCenter - 12.5f, trunkHeight);

    return bark;
}

RectangleShape ChristmasTreeStruct::createBark3(float trunkCenter, float trunkHeight, float trunkW, float trunkH)
{
    RectangleShape bark;

    bark.setSize(Vector2f(trunkW - 37.5f, trunkH - 24.0f));
    bark.setFillColor(Color(32, 24, 11)); // darkBrown
    bark.setPosition(trunkCenter - 6.25f, trunkHeight);

    return bark;
}

ConvexShape ChristmasTreeStruct::createTree(float trunkCenter, float trunkHeight, float *treeTip)
{
    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    ConvexShape christmasTree;

    christmasTree.setPointCount(19);
    christmasTree.setFillColor(Color(36, 92, 36));
    christmasTree.setOutlineColor(Color(25, 56, 25));
    christmasTree.setOutlineThickness(2.f);

    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    for (int i = 0; i < christmasTree.getPointCount(); i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
                *treeTip = currentHeight - verticalSpread;
            }
            else if (i % 2 != 0)
            {
                currentHeight = currentHeight - verticalSpread;
                treeDiv = treeDiv / 1.49;
                christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDiv, currentHeight));
            }
            else if (i % 2 == 0)
            {
                treeDec = treeDec - 35;
                christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDec, currentHeight));
            }
        }
        else if (i > 9)
        {
            if (i % 2 != 0)
            {
                christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDiv, currentHeight));
                currentHeight = currentHeight + verticalSpread;
                treeDiv = treeDiv * 1.49;
            }
            else if (i % 2 == 0)
            {
                christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDec, currentHeight));
                treeDec = treeDec + 35;
            }
        }
    }

    return christmasTree;
}

ConvexShape ChristmasTreeStruct::createStar(float trunkCenter, float treeTip)
{
    //------------------------- STAR MODEL -----------------------------//

    ConvexShape treeStar;

    treeStar.setPointCount(10);
    treeStar.setFillColor(Color().Yellow);
    treeStar.setOutlineThickness(3.f);
    treeStar.setOutlineColor(Color(255, 255, 0, 64));

    float starW = trunkCenter - 12.0f;
    float starH = treeTip + 14.0f;

    treeStar.setPosition(Vector2f(starW, starH));

    treeStar.setPoint(0, Vector2f(0.f, 0.f));
    treeStar.setPoint(1, Vector2f(+5.0f, -14.0f));
    treeStar.setPoint(2, Vector2f(-8.0f, -23.0f));
    treeStar.setPoint(3, Vector2f(+8.0f, -23.0f));
    treeStar.setPoint(4, Vector2f(+12.0f, -37.0f));
    treeStar.setPoint(5, Vector2f(+17.0f, -23.0f));
    treeStar.setPoint(6, Vector2f(+32.0f, -23.0f));
    treeStar.setPoint(7, Vector2f(+20.0f, -14.0f));
    treeStar.setPoint(8, Vector2f(+24.0f, 0.f));
    treeStar.setPoint(9, Vector2f(+12.0f, -7.0f));

    return treeStar;
}

