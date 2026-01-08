#include "Side.h"

Side::Side()
{

	this->setPosition(
			TOP_LEFT_X,
			TOP_LEFT_Y
			);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{

			pieces[i][j].setSize(Vector2f(PIECE_SIZE, PIECE_SIZE));

			//hardcode colors for now
			if(i == 0)
				pieces[i][j].setFillColor(Color::Blue);
			if(i == 1)
				pieces[i][j].setFillColor(Color::Red);
			if(i == 2)
				pieces[i][j].setFillColor(Color::Green);

		}
	}

}

void Side::update(GameState& currState, GameState& nextState)
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
				//update positions (to cater for rotations)
				this->setPosition(
						TOP_LEFT_X,
						TOP_LEFT_Y
						);
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
				//update positions (to cater for rotations)
				this->setPosition(
						TOP_LEFT_X,
						TOP_LEFT_Y
						);
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
void Side::draw(RenderWindow& window, GameState& currState, GameState& nextState)
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
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						window.draw(pieces[i][j]);
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
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						window.draw(pieces[i][j]);
					}
				}
				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						window.draw(pieces[i][j]);
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
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						window.draw(pieces[i][j]);
					}
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

void Side::setPosition(double x, double y)
{
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{

			pieces[i][j].setPosition(
					Vector2f(
						x + PIECE_SIZE*j + PADDING*j,
						y + PIECE_SIZE*i + PADDING*i
						)
					);
		}
	}
}


void Side::rotateCW()
{
	//rotate side clockwise

	//rotate corners
	RectangleShape temp = pieces[0][0];
	pieces[0][0] = pieces[2][0];
	pieces[2][0] = pieces[2][2];
	pieces[2][2] = pieces[0][2];
	pieces[0][2] = temp;

	//rotate edges
	temp = pieces[0][1];
	pieces[0][1] = pieces[1][0];
	pieces[1][0] = pieces[2][1];
	pieces[2][1] = pieces[1][2];
	pieces[1][2] = temp;
}
void Side::rotateCCW()
{
	//rotate side counterclockwise

	//rotate corners
	RectangleShape temp = pieces[0][0];
	pieces[0][0] = pieces[0][2];
	pieces[0][2] = pieces[2][2];
	pieces[2][2] = pieces[2][0];
	pieces[2][0] = temp;

	//rotate edges
	temp = pieces[0][1];
	pieces[0][1] = pieces[1][2];
	pieces[1][2] = pieces[2][1];
	pieces[2][1] = pieces[1][0];
	pieces[1][0] = temp;
}

void Side::shrinkLeft(Side startSide, float progress)
{
	Vector2f targetPos = {
		TOP_LEFT_X,
		TOP_LEFT_Y
			};
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//translate
			pieces[i][j].setPosition({
					startSide.getPiece(i,j).getPosition().x + (targetPos.x - startSide.getPiece(i,j).getPosition().x) * progress,
					startSide.getPiece(i,j).getPosition().y
					});

			//compress
			pieces[i][j].setScale({
					startSide.getPiece(i,j).getScale().x - (startSide.getPiece(i,j).getScale().x * progress),
					startSide.getPiece(i,j).getScale().y
					});
		}
	}
}

void Side::shrinkRight(Side startSide, float progress)
{

}
void Side::growLeft(Side startSide, float progress)
{
}
void Side::growRight(Side startSide, float progress)
{
}
