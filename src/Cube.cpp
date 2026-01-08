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
			
		//update all sides
		front->update(currState, nextState);
		back->update(currState, nextState);
		up->update(currState, nextState);
		down->update(currState, nextState);
		right->update(currState, nextState);
		left->update(currState, nextState);
	}
}
void Cube::draw(RenderWindow& window, GameState& currState, GameState& nextState)
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

}
void Cube::rotateDown(GameState& currState, GameState& nextState)
{

}
