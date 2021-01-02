#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

struct Scene
{
    RectangleShape trunk;
    ConvexShape christmasTree;
};

Scene createScene(int width, int height)
{
    Scene rv;

    float trunkCenter = (float)width / 2;
    float trunkHeight = (float)height - 60;

    rv.trunk.setSize(Vector2f(50, 60));
    rv.trunk.setFillColor(Color(71, 54, 24)); // 101, 67, 33
    rv.trunk.setPosition(trunkCenter-25, trunkHeight);

    //-------------------------CHRISTMAS TREE MODEL-----------------------------//

    rv.christmasTree.setPointCount(19);
    rv.christmasTree.setFillColor(Color(36, 92, 36));
    
    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    for (int i = 0; i < 19; i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
            }
            else if (i % 2 != 0)
            {
                currentHeight = currentHeight - verticalSpread;
                treeDiv = treeDiv / 1.49;
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDiv, currentHeight));
            }
            else if (i % 2 == 0)
            {
                treeDec = treeDec - 35;
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter - (float)treeDec, currentHeight));
            }
        }
        else if (i > 9)
        {
            if (i % 2 != 0)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDiv, currentHeight));
                currentHeight = currentHeight + verticalSpread;
                treeDiv = treeDiv * 1.49;
            }
            else if (i % 2 == 0)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter + (float)treeDec, currentHeight));
                treeDec = treeDec + 35;
            }
        }
    }

    return rv;
}

void drawScene(RenderWindow& win, const Scene& scene)
{
    win.draw(scene.trunk);
    win.draw(scene.christmasTree);
}
/*
void updateScene(Scene& scene)
{
    scene.trunk.move(0.f, -0.9f);
}
*/
int main()
{
    RenderWindow window(VideoMode(800, 600),"Merry Christmas!");
    window.setFramerateLimit(60);

    Scene sc = createScene(window.getSize().x, window.getSize().y);

    while(window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //updateScene(sc);
        
        window.clear();

        drawScene(window, sc);

        window.display();
    }

    return 0;
}