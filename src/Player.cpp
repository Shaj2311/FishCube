#include "Player.h"

Player::Player()
{

	if(!fishTexture.loadFromFile("fish.png")){exit(1);}
	fishSprite = new Sprite(fishTexture);


	fishSprite->setOrigin(
			{
			fishTexture.getSize().x / 2.f,
			fishTexture.getSize().y / 2.f
			}
			);

	fishSprite->setScale(
			{
			(PIECE_SIZE * 0.65f) / fishTexture.getSize().x,
			(PIECE_SIZE * 0.65f) / fishTexture.getSize().y
			}
			);

	fishSprite->setPosition({WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f});

	fishSprite->setColor(Color::Red);

	currentRow = currentCol = 1;
}

void Player::update(GameState& currState, GameState& nextState)
{
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

void Player::draw(RenderWindow& window, GameState& currState, GameState& nextState)
{
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
				window.draw(*fishSprite);
				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_UNSOLVED:
			{
				window.draw(*fishSprite);
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
			{
				window.draw(*fishSprite);
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
