#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Scene
{
    RectangleShape ground;
    RectangleShape trunk;
    ConvexShape christmasTree;
    ConvexShape star;
};

Scene createScene(int width, int height)
{
    Scene rv;

    //------------------------- GROUND MODEL -----------------------------//

    rv.ground.setSize(Vector2f((float)width, 20.f));
    rv.ground.setFillColor(Color(102, 89, 71));
    rv.ground.setPosition(0, (float)height - 20.f);

    //------------------------- TRUNK MODEL -----------------------------//

    float trunkCenter = (float)width / 2;
    float trunkHeight = (float)height - 60;

    rv.trunk.setSize(Vector2f(50, 60));
    rv.trunk.setFillColor(Color(71, 54, 24));
    rv.trunk.setPosition(trunkCenter - 25, trunkHeight);

    //------------------------- CHRISTMAS TREE MODEL -----------------------------//

    rv.christmasTree.setPointCount(19);
    rv.christmasTree.setFillColor(Color(36, 92, 36));

    double treeDiv = 200;
    double treeDec = 235;

    float verticalSpread = 60;
    float currentHeight = trunkHeight;

    float christmasTreeTip = 0;

    for (int i = 0; i < rv.christmasTree.getPointCount(); i++)
    {
        if (i <= 9)
        {
            if (i == 9)
            {
                rv.christmasTree.setPoint(i, Vector2f(trunkCenter, currentHeight - verticalSpread));
                christmasTreeTip = currentHeight - verticalSpread;
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

    //------------------------- STAR MODEL -----------------------------//

    rv.star.setPointCount(10);
    rv.star.setFillColor(Color().Yellow);
    //rv.star.setOrigin(Vector2f(trunkCenter, christmasTreeTip));

    float starW = trunkCenter - 12.0f;
    float starH = christmasTreeTip + 14.0f;

    rv.star.setPosition(Vector2f(starW, starH));

    rv.star.setPoint(0, Vector2f(0, 0));
    rv.star.setPoint(1, Vector2f(+5.0f, -14.0f)); //    +2.5 |----| -7.0
    rv.star.setPoint(2, Vector2f(-8.0f, -23.0f)); //    -4.0 |----| -11.5
    rv.star.setPoint(3, Vector2f(+8.0f, -23.0f)); //    +4.0 |----| -11.5
    rv.star.setPoint(4, Vector2f(+12.0f, -37.0f)); //   +6.0 |----| -18.5
    rv.star.setPoint(5, Vector2f(+17.0f, -23.0f)); //   +8.5 |----| -11.5
    rv.star.setPoint(6, Vector2f(+32.0f, -23.0f)); //  +16.0 |----| -11.5
    rv.star.setPoint(7, Vector2f(+20.0f, -14.0f)); //  +10.0 |----| -7.0
    rv.star.setPoint(8, Vector2f(+24.0f, 0)); //         +12.0 |----| nothing
    rv.star.setPoint(9, Vector2f(+12.0f, -7.0f)); //    +6.0 |----| -3.5

    return rv;
}

void drawScene(RenderWindow& win, const Scene& scene)
{
    win.draw(scene.ground);
    win.draw(scene.trunk);
    win.draw(scene.christmasTree);
    win.draw(scene.star);
}
/*
void updateScene(Scene& scene)
{
}
*/
int main()
{
    RenderWindow window(VideoMode(800, 600), "Merry Christmas!");
    window.setFramerateLimit(60);

    Scene sc = createScene(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //updateScene(sc);

        window.clear(Color(101, 114, 135));

        drawScene(window, sc);

        window.display();
    }

    return 0;
}