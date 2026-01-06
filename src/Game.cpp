#include "Game.h"

Game::Game()
{
	window.create(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "FishCube", State::Fullscreen);
	window.setFramerateLimit(60);
}

void Game::update()
{
	pollEvents();

	s.update();
}

void Game::draw()
{
	window.clear();
	s.draw(window);
	window.display();
}

void Game::pollEvents()
{
	//event handler
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();
	}
}
