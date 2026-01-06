#include "Game.h"

Game::Game()
{
	window.create(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "FishCube", State::Fullscreen);
	window.setFramerateLimit(60);
}

void Game::update(StateManager& sm)
{
	pollEvents(sm);

	s.update(sm);
}

void Game::draw(StateManager& sm)
{
	window.clear();
	s.draw(window, sm);
	window.display();
}

void Game::pollEvents(StateManager& sm)
{
	//event handler
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();


		GameState currState = sm.getState();
		switch(currState)
		{
			case START:
				{
					break;
				}
			case GAME_START:
				{
					break;
				}
			case IDLE_UNSOLVED:
				{
					break;
				}
			case IDLE_UNSOLVED_PAUSED:
				{
					break;
				}
			case MOVING_UNSOLVED:
				{
					break;
				}
			case MOVING_UNSOLVED_PAUSED:
				{
					break;
				}
			case IDLE_SOLVED:
				{
					break;
				}
			case IDLE_SOLVED_PAUSE:
				{
					break;
				}
			case MOVING_SOLVED:
				{
					break;
				}
			case MOVING_SOLVED_PAUSE:
				{
					break;
				}
			case WIN:
				{
					break;
				}
			case EXIT:
				{
					break;
				}
		}
	}
}
