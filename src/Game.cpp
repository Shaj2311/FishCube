#include "Game.h"

Game::Game()
{
	cube = new Cube();
	player = new Player();
	window.create(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "FishCube", State::Fullscreen);
	window.setFramerateLimit(60);

	uiFont = Font("assets/fonts/Roboto-Black.ttf");
	timerText = new Text(uiFont, "00:00:000", 40);
	pauseText = new Text(uiFont, "Press [ESC] to Pause", 40);
	timerText->setPosition({WINDOW_WIDTH - timerText->getLocalBounds().size.x, 0});
	pauseText->setPosition({0, 0});

	finalScore = 0;
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
				clock.restart();
				break;
			}
		case IDLE_UNSOLVED:
			{
				//check if cube is solved
				if(cube->isSolved())
				{
					nextState = WIN;
					clock.stop();
					finalScore = score.computeFinalScore(clock.getElapsedTime());
				}

				updateTimerText();
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

				updateTimerText();
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				//set player color
				player->setColor(Color(0,0,0,100));

				updateTimerText();
				break;
			}
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
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

				updateTimerText();
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
		case EXIT_CONFIRM:
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

	switch(currState)
	{
		case START:
		case GAME_START:
				 break;
		case IDLE_UNSOLVED:
		case MOVING_UNSOLVED:
				 window.draw(*pauseText);
				 window.draw(*timerText);
				 break;
		case IDLE_SOLVED:
		case MOVING_SOLVED:
		case IDLE_UNSOLVED_PAUSED:
		case MOVING_UNSOLVED_PAUSED:
		case IDLE_SOLVED_PAUSED:
		case MOVING_SOLVED_PAUSED:
		case WIN:
		case EXIT_CONFIRM:
		case EXIT:
				 break;
	}
	drawMenu(window, currState, &finalScore);
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
						//start game
						if(keyPressed->code == Keyboard::Key::Enter)
						{
							nextState = GAME_START;
						}
						//exit
						if(keyPressed->code == Keyboard::Key::Q)
						{
							nextState = EXIT_CONFIRM;
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
						//WASD, Space for color swap, Escape to pause
						if(keyPressed->code == Keyboard::Key::W || keyPressed->code == Keyboard::Key::Up)
						{
							//UP PRESSED
							if(player->getRow() == 0 && isValidMove(DOWN_2))
								player->setDirection(DOWN_2);
							else if(player->getRow() != 0 && isValidMove(UP_1))
								player->setDirection(UP_1);
							else break;

							score.addMove();

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::S || keyPressed->code == Keyboard::Key::Down)
						{
							//DOWN PRESSED
							if(player->getRow() == 2 && isValidMove(UP_2))
								player->setDirection(UP_2);
							else if(player->getRow() != 2 && isValidMove(DOWN_1))
								player->setDirection(DOWN_1);
							else break;

							score.addMove();

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::A || keyPressed->code == Keyboard::Key::Left)
						{
							//LEFT PRESSED
							if(player->getCol() == 0 && isValidMove(RIGHT_2))
								player->setDirection(RIGHT_2);
							else if(player->getCol() != 0 && isValidMove(LEFT_1))
								player->setDirection(LEFT_1);
							else break;

							score.addMove();

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::D || keyPressed->code == Keyboard::Key::Right)
						{
							//RIGHT PRESSED
							if(player->getCol() == 2 && isValidMove(LEFT_2))
								player->setDirection(LEFT_2);
							else if(player->getCol() != 2 && isValidMove(RIGHT_1))
								player->setDirection(RIGHT_1);
							else break;

							score.addMove();

							//set next state
							nextState = MOVING_UNSOLVED;
						}
						if(keyPressed->code == Keyboard::Key::Space)
						{
							swapColors();
							score.addSwap();
						}
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//pause
							nextState = IDLE_UNSOLVED_PAUSED;
							clock.stop();
						}
					}
					break;
				}
			case IDLE_UNSOLVED_PAUSED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//resume
							nextState = IDLE_UNSOLVED;
							clock.start();
						}
						if(keyPressed->code == Keyboard::Key::Q)
						{
							//go to start menu
							nextState = START;
						}
						if(keyPressed->code == Keyboard::Key::R)
						{
							//restart
							nextState = GAME_START;
						}
					}
					break;
				}
			case MOVING_UNSOLVED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//pause
							nextState = MOVING_UNSOLVED_PAUSED;
							clock.stop();
						}
					}
					break;
				}
			case MOVING_UNSOLVED_PAUSED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//resume
							nextState = MOVING_UNSOLVED;
							clock.start();
						}
						if(keyPressed->code == Keyboard::Key::Q)
						{
							//go to start menu
							nextState = START;
						}
						if(keyPressed->code == Keyboard::Key::R)
						{
							//restart
							nextState = GAME_START;
						}
					}
					break;
				}
			case IDLE_SOLVED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						//WASD, Escape to pause
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
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//pause
							nextState = IDLE_SOLVED_PAUSED;
							clock.stop();
						}
					}
					break;
				}
			case IDLE_SOLVED_PAUSED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//resume
							nextState = IDLE_SOLVED;
							clock.start();
						}
						if(keyPressed->code == Keyboard::Key::Q)
						{
							//go to start menu
							nextState = START;
						}
						if(keyPressed->code == Keyboard::Key::R)
						{
							//restart
							nextState = GAME_START;
						}
					}
					break;
				}
			case MOVING_SOLVED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//pause
							nextState = MOVING_SOLVED_PAUSED;
							clock.stop();
						}
					}
					break;
				}
			case MOVING_SOLVED_PAUSED:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Escape)
						{
							//resume
							nextState = MOVING_SOLVED;
							clock.start();
						}
						if(keyPressed->code == Keyboard::Key::Q)
						{
							//go to start menu
							nextState = START;
						}
						if(keyPressed->code == Keyboard::Key::R)
						{
							//restart
							nextState = GAME_START;
						}
					}
					break;
				}
			case WIN:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						if(keyPressed->code == Keyboard::Key::Enter)
						{
							//explore
							nextState = IDLE_SOLVED;
						}
						if(keyPressed->code == Keyboard::Key::Q)
						{
							//go to start menu
							nextState = START;
						}
						if(keyPressed->code == Keyboard::Key::R)
						{
							//restart
							nextState = GAME_START;
						}
					}
					break;
				}
			case EXIT_CONFIRM:
				{
					if(const auto keyPressed = event->getIf<Event::KeyPressed>())
					{
						//exit
						if(keyPressed->code == Keyboard::Key::Y)
						{
							nextState = EXIT;
						}
						//back to start
						if(keyPressed->code == Keyboard::Key::N)
						{
							nextState = START;
						}
					}
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

bool Game::isValidMove(Direction dir)
{
	Side* targetSide;
	RectangleShape targetPiece;
	int currRow = player->getRow();
	int currCol = player->getCol();
	Color playerColor = player->getColor();

	switch(dir)
	{
		case UP_1:
			targetSide = cube->getFrontSide();
			targetPiece = targetSide->getPiece(currRow-1, currCol);
			break;
		case DOWN_1:
			targetSide = cube->getFrontSide();
			targetPiece = targetSide->getPiece(currRow+1, currCol);
			break;
		case LEFT_1:
			targetSide = cube->getFrontSide();
			targetPiece = targetSide->getPiece(currRow, currCol-1);
			break;
		case RIGHT_1:
			targetSide = cube->getFrontSide();
			targetPiece = targetSide->getPiece(currRow, currCol+1);
			break;

		case UP_2:
			targetSide = cube->getDownSide();
			targetPiece = targetSide->getPiece(0, currCol);
			break;
		case DOWN_2:
			targetSide = cube->getUpSide();
			targetPiece = targetSide->getPiece(2, currCol);
			break;
		case LEFT_2:
			targetSide = cube->getRightSide();
			targetPiece = targetSide->getPiece(currRow, 0);
			break;
		case RIGHT_2:
			targetSide = cube->getLeftSide();
			targetPiece = targetSide->getPiece(currRow, 2);
			break;
	}

	if(targetPiece.getFillColor() == playerColor)
		return false;
	return true;
}

void Game::updateTimerText()
{
	int time = clock.getElapsedTime().asMilliseconds();
	int minutes, seconds, mSeconds;
	minutes = time/60000;
	seconds = (time/1000) % 60;
	mSeconds = time % 1000;

	std::string timerStr =
		std::to_string(minutes) + ":" +
		std::to_string(seconds) + ":" +
		std::to_string(mSeconds).substr(0,3);

	timerText->setString(timerStr);
}
