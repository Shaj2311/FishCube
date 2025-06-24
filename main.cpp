#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameManager.h"
#include "WindowSize.h"
using namespace sf;

int main()
{
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "FishCube");
        window.setFramerateLimit(60);
        window.setPosition(Vector2i(1920, 0)); //temporary (for debugging convenience)

        Clock clock;

        GameManager manager;



        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();


                        if (event.type == sf::Event::KeyPressed)
                        {
                                Player& player = manager.getPlayer();

                                if (!player.getIsMoving()) // prevents command spamming mid-move
                                {
                                        if (event.key.code == sf::Keyboard::W) manager.move(Player::UP);
                                        if (event.key.code == sf::Keyboard::D) manager.move(Player::RIGHT);
                                        if (event.key.code == sf::Keyboard::S) manager.move(Player::DOWN);
                                        if (event.key.code == sf::Keyboard::A) manager.move(Player::LEFT);
                                }
                        }
                }

                


                double deltaTime = clock.restart().asSeconds();

                manager.update(deltaTime);

                window.clear();
                manager.draw(window);
                window.display();
        }

        return 0;
}
