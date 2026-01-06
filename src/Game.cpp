#include "Game.h"

Game::Game()
{
	window.create(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "FishCube", State::Fullscreen);
	window.setFramerateLimit(60);
}

void Game::update(GameState& currState, GameState& nextState)
{
	switch(currState)
	{
		case START:
			{
				break;
			}
		case GAME_START:
			{
				//reset side
				s = new Side();
				//start game
				nextState = IDLE_UNSOLVED;
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
	pollEvents(currState, nextState);

	s->update(currState, nextState);
}

void Game::draw(GameState& currState, GameState& nextState)
{
	window.clear();
	s->draw(window, currState, nextState);
	window.display();
}

void Game::pollEvents(GameState& currState, GameState& nextState)
{
	//event handler
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();


		switch(currState)
		{
			case START:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						//if enter pressed, start game
						if(keyPressed->code == Keyboard::Key::Enter)
						{
							nextState = GAME_START;
						}
					}
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
