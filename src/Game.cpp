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
				//reset player
				p = new Player();

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
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
			{
				break;
			}
		case MOVING_SOLVED_PAUSED:
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
	p->update(currState, nextState);
}

void Game::draw(GameState& currState, GameState& nextState)
{
	window.clear();
	s->draw(window, currState, nextState);
	p->draw(window, currState, nextState);
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
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						//WASD
						if(keyPressed->code == Keyboard::Key::W || keyPressed->code == Keyboard::Key::Up)
						{
							//UP PRESSED
							if(p->getRow() == 0)
								p->setDirection(DOWN_2);
							else
								p->setDirection(UP_1);
						}
						if(keyPressed->code == Keyboard::Key::S || keyPressed->code == Keyboard::Key::Down)
						{
							//UP PRESSED
							if(p->getRow() == 2)
								p->setDirection(UP_2);
							else
								p->setDirection(DOWN_1);
						}
						if(keyPressed->code == Keyboard::Key::A || keyPressed->code == Keyboard::Key::Left)
						{
							//UP PRESSED
							if(p->getCol() == 0)
								p->setDirection(RIGHT_2);
							else
								p->setDirection(LEFT_1);
						}
						if(keyPressed->code == Keyboard::Key::D || keyPressed->code == Keyboard::Key::Right)
						{
							//UP PRESSED
							if(p->getCol() == 2)
								p->setDirection(LEFT_2);
							else
								p->setDirection(RIGHT_1);
						}

						//set next state
						nextState = MOVING_UNSOLVED;
					}
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
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						//WASD
						if(keyPressed->code == Keyboard::Key::W || keyPressed->code == Keyboard::Key::Up)
						{
							//UP PRESSED
							if(p->getRow() == 0)
								p->setDirection(DOWN_2);
							else
								p->setDirection(UP_1);
						}
						if(keyPressed->code == Keyboard::Key::S || keyPressed->code == Keyboard::Key::Down)
						{
							//UP PRESSED
							if(p->getRow() == 2)
								p->setDirection(UP_2);
							else
								p->setDirection(DOWN_1);
						}
						if(keyPressed->code == Keyboard::Key::A || keyPressed->code == Keyboard::Key::Left)
						{
							//UP PRESSED
							if(p->getCol() == 0)
								p->setDirection(RIGHT_2);
							else
								p->setDirection(LEFT_1);
						}
						if(keyPressed->code == Keyboard::Key::D || keyPressed->code == Keyboard::Key::Right)
						{
							//UP PRESSED
							if(p->getCol() == 2)
								p->setDirection(LEFT_2);
							else
								p->setDirection(RIGHT_1);
						}

						//set next state
						nextState = MOVING_SOLVED;
					}
					break;
				}
			case IDLE_SOLVED_PAUSED:
				{
					break;
				}
			case MOVING_SOLVED:
				{
					break;
				}
			case MOVING_SOLVED_PAUSED:
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
