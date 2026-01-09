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
				//reset cube
				cube = new Cube();
				//reset player
				player = new Player();

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
				//if cube needs rotation, rotate it
				if(player->getDirection() == LEFT_2)
					cube->rotateLeft(currState, nextState);
				if(player->getDirection() == RIGHT_2)
					cube->rotateRight(currState, nextState);
				if(player->getDirection() == DOWN_2)
					cube->rotateDown(currState, nextState);
				if(player->getDirection() == UP_2)
					cube->rotateUp(currState, nextState);
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

	cube->update(currState, nextState);
	player->update(currState, nextState);
}

void Game::draw(GameState& currState, GameState& nextState)
{
	window.clear();
	cube->draw(window, currState, nextState, player->getDirection());
	player->draw(window, currState, nextState);
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
						//WASD, Space for color swap
						if(keyPressed->code == Keyboard::Key::W || keyPressed->code == Keyboard::Key::Up)
						{
							//UP PRESSED
							if(player->getRow() == 0)
								player->setDirection(DOWN_2);
							else
								player->setDirection(UP_1);

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::S || keyPressed->code == Keyboard::Key::Down)
						{
							//DOWN PRESSED
							if(player->getRow() == 2)
								player->setDirection(UP_2);
							else
								player->setDirection(DOWN_1);

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::A || keyPressed->code == Keyboard::Key::Left)
						{
							//LEFT PRESSED
							if(player->getCol() == 0)
								player->setDirection(RIGHT_2);
							else
								player->setDirection(LEFT_1);

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::D || keyPressed->code == Keyboard::Key::Right)
						{
							//RIGHT PRESSED
							if(player->getCol() == 2)
								player->setDirection(LEFT_2);
							else
								player->setDirection(RIGHT_1);

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::Space)
						{
							swapColors();
						}
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
							if(player->getRow() == 0)
								player->setDirection(DOWN_2);
							else
								player->setDirection(UP_1);

							//set next state
							nextState = MOVING_SOLVED;
						}
						if(keyPressed->code == Keyboard::Key::S || keyPressed->code == Keyboard::Key::Down)
						{
							//UP PRESSED
							if(player->getRow() == 2)
								player->setDirection(UP_2);
							else
								player->setDirection(DOWN_1);

							//set next state
							nextState = MOVING_SOLVED;
						}
						if(keyPressed->code == Keyboard::Key::A || keyPressed->code == Keyboard::Key::Left)
						{
							//UP PRESSED
							if(player->getCol() == 0)
								player->setDirection(RIGHT_2);
							else
								player->setDirection(LEFT_1);

							//set next state
							nextState = MOVING_SOLVED;
						}
						if(keyPressed->code == Keyboard::Key::D || keyPressed->code == Keyboard::Key::Right)
						{
							//UP PRESSED
							if(player->getCol() == 2)
								player->setDirection(LEFT_2);
							else
								player->setDirection(RIGHT_1);

							//set next state
							nextState = MOVING_SOLVED;
						}
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

void Game::swapColors()
{
	//swap player and piece colors
	int row = player->getRow();
	int col = player->getCol();

	Color playerColor = player->getColor();
	RectangleShape& currentPiece = cube->getFrontSide()->getPiece(row, col);

	player->setColor(currentPiece.getFillColor());
	currentPiece.setFillColor(playerColor);
}
