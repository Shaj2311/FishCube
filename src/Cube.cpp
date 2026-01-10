#include "Cube.h"

Cube::Cube()
{
	//initialize colors
	Color* colorsArr = initColors();

	//initialize sides
	front = new Side();
	back = new Side();
	up = new Side();
	down = new Side();
	right = new Side();
	left = new Side();

	progress = 0.f;
	startingFrontSide = *front;
	startingTargetSide = *right;

	//assign colors
	Side* cube[6] = {front, back, up, down, right, left};
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				cube[i]->
					getPiece(j,k).
					setFillColor(colorsArr[(9*i) + (3*j + k)]);
			}
		}
	}
}

Color* Cube::initColors()
{
	Color* cubeColors = new Color[54];
	Color colors[6] = 
	{
		Color::White, Color::Yellow,
		Color::Blue, Color::Green,
		Color::Red, Color(255, 165, 0)
	};

	//initialize colors array
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cubeColors[(9*i) + j] = colors[i];
		}
	}

	////randomize with Fisher Yates
	//for(int i = 53; i > 0; i--)
	//{

	//	//get random value between 0 and i
	//	int swapIndex = rand() % (i+1);

	//	//skip centers
	//	if(i%9 == 4)
	//		continue;
	//	if(swapIndex%9 == 4)
	//		continue;

	//	//swap index i with random index
	//	Color temp = cubeColors[i];
	//	cubeColors[i] = cubeColors[swapIndex];
	//	cubeColors[swapIndex] = temp;
	//}
	Color temp = cubeColors[0];
	cubeColors[0] = cubeColors[10];
	cubeColors[10] = temp;

	return cubeColors;
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
	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingTargetSide = *left;
	}

	//interpolate
	front->shrinkRight(startingFrontSide, progress);
	left->growRight(startingTargetSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes, scales, colors
		*front = startingFrontSide;
		*left = startingTargetSide;

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
	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingTargetSide = *right;
	}

	//interpolate
	front->shrinkLeft(startingFrontSide, progress);
	right->growLeft(startingTargetSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes, scales, colors
		*front = startingFrontSide;
		*right = startingTargetSide;

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
	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingTargetSide = *down;
	}

	//interpolate
	front->shrinkUp(startingFrontSide, progress);
	down->growUp(startingTargetSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes, scales, colors
		*front = startingFrontSide;
		*down = startingTargetSide;

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
	if(progress == 0.f)
	{
		//mark initial state of sides
		startingFrontSide = *front;
		startingTargetSide = *up;
	}

	//interpolate
	front->shrinkDown(startingFrontSide, progress);
	up->growDown(startingTargetSide, progress);

	//update progress
	progress += MOVE_FACTOR;

	//animation complete
	if(progress >= 1.f)
	{
		//reset progress
		progress = 0.f;

		//reset sizes, scales, colors
		*front = startingFrontSide;
		*up = startingTargetSide;

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

bool Cube::isSolved()
{
	if(
			front->isSolved() && 
			right->isSolved() && 
			left->isSolved() && 
			up->isSolved() && 
			down->isSolved() && 
			back->isSolved()
	  )
		return true;
	return false;
}
