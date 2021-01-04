#pragma once

#include <tuple>
#include "SFML/Graphics.hpp"
#include "christmasTreeDecorations.h"

using namespace sf;

struct christmasTreeStruct
{
    ConvexShape christmasTree;
    ConvexShape christmasTreeStar;
};

christmasTreeStruct createChristmasTree(float trunkCenter, float trunkHeight)
{
    christmasTreeStruct cts;

    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    cts.christmasTree.setPointCount(19);
    cts.christmasTree.setFillColor(Color(36, 92, 36));

    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    float christmasTreeTip = 0;

    float pointEightX = 0;
    float pointEightY = 0;

    for (int i = 0; i < cts.christmasTree.getPointCount(); i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                cts.christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
                christmasTreeTip = currentHeight - verticalSpread;
            }
            else if (i % 2 != 0)
            {
                currentHeight = currentHeight - verticalSpread;
                treeDiv = treeDiv / 1.49;
                cts.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDiv, currentHeight));
            }
            else if (i % 2 == 0)
            {
                treeDec = treeDec - 35;
                cts.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDec, currentHeight));

                if (i == 8)
                {
                    pointEightX = trunkCenter - (float)treeDec;
                    pointEightY = currentHeight;
                }
            }
        }
        else if (i > 9)
        {
            if (i % 2 != 0)
            {
                cts.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDiv, currentHeight));
                currentHeight = currentHeight + verticalSpread;
                treeDiv = treeDiv * 1.49;
            }
            else if (i % 2 == 0)
            {
                cts.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDec, currentHeight));
                treeDec = treeDec + 35;
            }
        }
    }

    //------------------------- STAR MODEL -----------------------------//

    cts.christmasTreeStar.setPointCount(10);
    cts.christmasTreeStar.setFillColor(Color().Yellow);

    float starW = trunkCenter - 12.0f;
    float starH = christmasTreeTip + 14.0f;

    cts.christmasTreeStar.setPosition(Vector2f(starW, starH));

    cts.christmasTreeStar.setPoint(0, Vector2f(0.f, 0.f));
    cts.christmasTreeStar.setPoint(1, Vector2f(+5.0f, -14.0f));
    cts.christmasTreeStar.setPoint(2, Vector2f(-8.0f, -23.0f));
    cts.christmasTreeStar.setPoint(3, Vector2f(+8.0f, -23.0f));
    cts.christmasTreeStar.setPoint(4, Vector2f(+12.0f, -37.0f));
    cts.christmasTreeStar.setPoint(5, Vector2f(+17.0f, -23.0f));
    cts.christmasTreeStar.setPoint(6, Vector2f(+32.0f, -23.0f));
    cts.christmasTreeStar.setPoint(7, Vector2f(+20.0f, -14.0f));
    cts.christmasTreeStar.setPoint(8, Vector2f(+24.0f, 0.f));
    cts.christmasTreeStar.setPoint(9, Vector2f(+12.0f, -7.0f));

    return cts;
}