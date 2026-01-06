#include "Side.h"

Side::Side()
{

	this->setPosition(100, 100);
	this->setPosition(
			(WINDOW_WIDTH/2) - (3*PIECE_SIZE + 2*PADDING) / 2,
			(WINDOW_HEIGHT/2) - (3*PIECE_SIZE + 2*PADDING) / 2
			);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{

			pieces[i][j].setSize(Vector2f(PIECE_SIZE, PIECE_SIZE));

			//hardcode colors for now
			if(i == 0)
				pieceColors[i][j] = Color::Blue;
			if(i == 1)
				pieceColors[i][j] = Color::Red;
			if(i == 2)
				pieceColors[i][j] = Color::Green;

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
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_1_UNSOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_RIGHT_1_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_2_UNSOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_RIGHT_2_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_1_UNSOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_LEFT_1_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_2_UNSOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_LEFT_2_UNSOLVED_PAUSED:
			{
				break;
			}
		case IDLE_SOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case IDLE_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_1_SOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_RIGHT_1_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_2_SOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_RIGHT_2_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_1_SOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_LEFT_1_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_2_SOLVED:
			{
				//update colors
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						pieces[i][j].setFillColor(pieceColors[i][j]);
					}
				}
				break;
			}
		case MOVING_LEFT_2_SOLVED_PAUSED:
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
		case MOVING_RIGHT_1_UNSOLVED:
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
		case MOVING_RIGHT_1_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_2_UNSOLVED:
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
		case MOVING_RIGHT_2_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_1_UNSOLVED:
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
		case MOVING_LEFT_1_UNSOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_2_UNSOLVED:
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
		case MOVING_LEFT_2_UNSOLVED_PAUSED:
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
		case MOVING_RIGHT_1_SOLVED:
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
		case MOVING_RIGHT_1_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_RIGHT_2_SOLVED:
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
		case MOVING_RIGHT_2_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_1_SOLVED:
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
		case MOVING_LEFT_1_SOLVED_PAUSED:
			{
				break;
			}
		case MOVING_LEFT_2_SOLVED:
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
		case MOVING_LEFT_2_SOLVED_PAUSED:
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
