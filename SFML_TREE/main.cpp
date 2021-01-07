#include "SFML/Graphics.hpp"
#include "generateScene.h"

int main()
{
    RenderWindow window(VideoMode(800, 600), "Merry Christmas!");
    window.setFramerateLimit(60);

    srand(time(NULL));

    Scene sc = createScene(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        updateScene(sc);

        window.clear();

        drawScene(window, sc);

        window.display();
    }
    return 0;
}