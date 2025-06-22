#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameManager.h"
using namespace sf;

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "FishCube");
        window.setFramerateLimit(60);
        window.setPosition(Vector2i(1920, 0)); //temporary (for debugging convenience)

        GameManager manager;



        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                manager.update();

                window.clear();
                manager.draw(window);
                window.display();
        }

        return 0;
}
