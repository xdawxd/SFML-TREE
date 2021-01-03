#pragma once

#include "SFML/Graphics.hpp"
#include "christmasTreeStar.h"

using namespace sf;

auto createChrismasTree(float trunkCenter, float trunkHeight, ConvexShape *christmasTreeStar)
{
	ConvexShape christmasTree;

    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    christmasTree.setPointCount(19);
    christmasTree.setFillColor(Color(36, 92, 36));

    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    float christmasTreeTip = 0;

    for (int i = 0; i < christmasTree.getPointCount(); i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
                christmasTreeTip = currentHeight - verticalSpread;
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

    *christmasTreeStar = createChristmasTreeStar(trunkCenter, christmasTreeTip);
    return christmasTree;
}