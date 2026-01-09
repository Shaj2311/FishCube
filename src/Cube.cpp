#include "Cube.h"

Cube::Cube()
{
	//initialize sides
	front = new Side();
	back = new Side();
	up = new Side();
	down = new Side();
	right = new Side();
	left = new Side();
}

void Cube::update(GameState& currState, GameState& nextState)
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
				//update all sides
				front->update(currState, nextState);
				back->update(currState, nextState);
				up->update(currState, nextState);
				down->update(currState, nextState);
				right->update(currState, nextState);
				left->update(currState, nextState);
				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_UNSOLVED:
			{
				//update all sides
				front->update(currState, nextState);
				back->update(currState, nextState);
				up->update(currState, nextState);
				down->update(currState, nextState);
				right->update(currState, nextState);
				left->update(currState, nextState);
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				break;
				//update all sides
				front->update(currState, nextState);
				back->update(currState, nextState);
				up->update(currState, nextState);
				down->update(currState, nextState);
				right->update(currState, nextState);
				left->update(currState, nextState);
			}
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
			{
				//update all sides
				front->update(currState, nextState);
				back->update(currState, nextState);
				up->update(currState, nextState);
				down->update(currState, nextState);
				right->update(currState, nextState);
				left->update(currState, nextState);
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
void Cube::draw(RenderWindow& window, GameState& currState, GameState& nextState, Direction dir = RIGHT_1)
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
				front->draw(window, currState, nextState);
				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_UNSOLVED:
			{
				front->draw(window, currState, nextState);
				if(nextState == IDLE_UNSOLVED) break;
				switch(dir)
				{
					case LEFT_2:
						right->draw(window, currState, nextState);
						break;
					case RIGHT_2:
						left->draw(window, currState, nextState);
						break;
					case UP_2:
						down->draw(window, currState, nextState);
						break;
					case DOWN_2:
						up->draw(window, currState, nextState);
						break;
				}
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				front->draw(window, currState, nextState);
				break;
			}
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_SOLVED:
			{
				front->draw(window, currState, nextState);
				if(nextState == IDLE_SOLVED) break;
				switch(dir)
				{
					case LEFT_2:
						left->draw(window, currState, nextState);
						break;
					case RIGHT_2:
						right->draw(window, currState, nextState);
						break;
					case UP_2:
						up->draw(window, currState, nextState);
						break;
					case DOWN_2:
						down->draw(window, currState, nextState);
						break;
				}
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

void Cube::rotateRight(GameState& currState, GameState& nextState)
{
	static float progress = 0.f;
	static Side startingFrontSide = *front;
	static Side startingLeftSide = *right;

	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingLeftSide = *left;
	}

	//interpolate
	front->shrinkRight(startingFrontSide, progress);
	left->growRight(startingLeftSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes and scales
		*front = startingFrontSide;
		*left = startingLeftSide;

		//update sides
		Side* temp = front;
		front = left;
		left = back;
		back = right;
		right = temp;
		up->rotateCCW();
		down->rotateCW();

		//update state
		if(currState == MOVING_UNSOLVED)
			nextState = IDLE_UNSOLVED;
		if(currState == MOVING_SOLVED)
			nextState = IDLE_SOLVED;
	}
}
void Cube::rotateLeft(GameState& currState, GameState& nextState)
{
	static float progress = 0.f;
	static Side startingFrontSide = *front;
	static Side startingRightSide = *right;

	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingRightSide = *right;
	}

	//interpolate
	front->shrinkLeft(startingFrontSide, progress);
	right->growLeft(startingRightSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes and scales
		*front = startingFrontSide;
		*right = startingRightSide;

		//update sides
		Side* temp = front;
		front = right;
		right = back;
		back = left;
		left = temp;
		up->rotateCW();
		down->rotateCCW();

		//update state
		if(currState == MOVING_UNSOLVED)
			nextState = IDLE_UNSOLVED;
		if(currState == MOVING_SOLVED)
			nextState = IDLE_SOLVED;
	}
}
void Cube::rotateUp(GameState& currState, GameState& nextState)
{
	static float progress = 0.f;
	static Side startingFrontSide = *front;
	static Side startingDownSide = *down;

	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingDownSide = *down;
	}

	//NO ANIMATIONS FOR NOW
	////interpolate
	//front->shrinkLeft(startingFrontSide, progress);
	//right->growLeft(startingRightSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//update sides
		Side* temp = front;
		front = down;
		down = back;
		back = up;
		up = temp;
		left->rotateCCW();
		right->rotateCW();

		back->rotateCW();
		back->rotateCW();
		down->rotateCW();
		down->rotateCW();

		//update state
		if(currState == MOVING_UNSOLVED)
			nextState = IDLE_UNSOLVED;
		if(currState == MOVING_SOLVED)
			nextState = IDLE_SOLVED;
	}

}
void Cube::rotateDown(GameState& currState, GameState& nextState)
{
	static float progress = 0.f;
	static Side startingFrontSide = *front;
	static Side startingUpSide = *up;

	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingUpSide = *up;
	}

	//NO ANIMATIONS FOR NOW
	////interpolate
	//front->shrinkLeft(startingFrontSide, progress);
	//right->growLeft(startingRightSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//update sides
		Side* temp = front;
		front = up;
		up = back;
		back = down;
		down = temp;
		left->rotateCW();
		right->rotateCCW();

		back->rotateCW();
		back->rotateCW();
		up->rotateCW();
		up->rotateCW();

		//update state
		if(currState == MOVING_UNSOLVED)
			nextState = IDLE_UNSOLVED;
		if(currState == MOVING_SOLVED)
			nextState = IDLE_SOLVED;
	}
}
