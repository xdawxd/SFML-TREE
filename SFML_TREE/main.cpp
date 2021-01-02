#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"

using namespace sf;

int width = 800, height = 600;

struct Scene
{
    sf::RectangleShape trunk;
};

Scene createScene()
{
    Scene rv;

    rv.trunk.setSize(sf::Vector2f(60, 50));
    rv.trunk.setFillColor(sf::Color(101, 67, 33));
    rv.trunk.setRotation(90.f);

    rv.trunk.setPosition(width/2, height-60);

    return rv;
}

void drawScene(sf::RenderWindow& win, const Scene& scene)
{
    win.draw(scene.trunk);
}
/*
void updateScene(Scene& scene)
{
    
}
*/
int main()
{
    RenderWindow window(sf::VideoMode(width, height),"Merry Christmas!");
    
    Scene sc = createScene();

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //updateScene(sc);

        window.clear();

        drawScene(window, sc);

        window.display();
    }

    return 0;
}