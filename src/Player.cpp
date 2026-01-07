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
				//reset move progress
				moveProgress = 0.f;
				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_UNSOLVED:
			{
				//move player
				move(currState, nextState);
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				//reset move progress
				moveProgress = 0.f;
				break;
			}
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
			{
				//move player
				move(currState, nextState);
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
		case IDLE_SOLVED:
			{
				window.draw(*fishSprite);
				break;
			}
		case IDLE_SOLVED_PAUSED:
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


void Player::move(GameState& currState, GameState& nextState)
{
	static Vector2f startingPos = fishSprite->getPosition();

	//compute target position and update current row/col
	static Vector2f targetPos = startingPos;
	if(moveProgress == 0.f) //compute only on first move frame
	{
		switch(direction)
		{
			case LEFT_1:
				targetPos.x -= PIECE_SIZE;
				currentCol -= 1;
				break;
			case LEFT_2:
				targetPos.x -= PIECE_SIZE*2;
				currentCol -= 2;
				break;
			case RIGHT_1:
				targetPos.x += PIECE_SIZE;
				currentCol += 1;
				break;
			case RIGHT_2:
				targetPos.x += PIECE_SIZE*2;
				currentCol += 2;
				break;
			case UP_1:
				targetPos.y -= PIECE_SIZE;
				currentRow -= 1;
				break;
			case UP_2:
				targetPos.y -= PIECE_SIZE*2;
				currentRow -= 2;
				break;
			case DOWN_1:
				targetPos.y += PIECE_SIZE;
				currentRow += 1;
				break;
			case DOWN_2:
				targetPos.y += PIECE_SIZE*2;
				currentRow += 2;
				break;
		}

	}

	//move player
	fishSprite->setPosition({
			startingPos.x + (targetPos.x - startingPos.x) * moveProgress,
			startingPos.y + (targetPos.y - startingPos.y) * moveProgress
			});

	//update progress
	moveProgress += MOVE_FACTOR;

	//reset and switch state if destination reached
	if(moveProgress >= 1.f)
	{
		//switch back to idle
		if(currState == MOVING_UNSOLVED)
			nextState = IDLE_UNSOLVED;
		if(currState == MOVING_SOLVED)
			nextState = IDLE_SOLVED;

		//reset static vars
		startingPos = fishSprite->getPosition();
	}

}
