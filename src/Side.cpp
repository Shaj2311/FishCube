#include "Side.h"

Side::Side()
{

	this->setPosition(
			CUBE_LEFT_X,
			CUBE_TOP_Y
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
						CUBE_LEFT_X,
						CUBE_TOP_Y
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
						CUBE_LEFT_X,
						CUBE_TOP_Y
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
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					startPiece.getPosition().x + (CUBE_LEFT_X - startPiece.getPosition().x) * progress,
					startPiece.getPosition().y
					});

			//compress
			pieces[i][j].setScale({
					startPiece.getScale().x - (startPiece.getScale().x * progress),
					startPiece.getScale().y
					});

			//dim
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t(startColor.r + (dimmedRed - startColor.r) * progress),
					uint8_t(startColor.g + (dimmedGreen - startColor.g) * progress),
					uint8_t(startColor.b + (dimmedBlue -startColor.b) * progress)
					});
		}
	}
}

void Side::shrinkRight(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					startPiece.getPosition().x + (CUBE_RIGHT_X - startPiece.getPosition().x) * progress,
					startPiece.getPosition().y
					});

			//compress
			pieces[i][j].setScale({
					startPiece.getScale().x - (startPiece.getScale().x * progress),
					startPiece.getScale().y
					});

			//dim
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t(startColor.r + (dimmedRed - startColor.r) * progress),
					uint8_t(startColor.g + (dimmedGreen - startColor.g) * progress),
					uint8_t(startColor.b + (dimmedBlue -startColor.b) * progress)
					});
		}
	}
}
void Side::shrinkUp(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					startPiece.getPosition().x,
					startPiece.getPosition().y + (CUBE_TOP_Y - startPiece.getPosition().y) * progress
					});

			//compress
			pieces[i][j].setScale({
					startPiece.getScale().x,
					startPiece.getScale().y - (startPiece.getScale().y * progress)
					});

			//dim
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t(startColor.r + (dimmedRed - startColor.r) * progress),
					uint8_t(startColor.g + (dimmedGreen - startColor.g) * progress),
					uint8_t(startColor.b + (dimmedBlue -startColor.b) * progress)
					});
		}
	}
}
void Side::shrinkDown(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					startPiece.getPosition().x,
					startPiece.getPosition().y + (CUBE_BOTTOM_Y - startPiece.getPosition().y) * progress
					});

			//compress
			pieces[i][j].setScale({
					startPiece.getScale().x,
					startPiece.getScale().y - (startPiece.getScale().y * progress)
					});

			//dim
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t(startColor.r + (dimmedRed - startColor.r) * progress),
					uint8_t(startColor.g + (dimmedGreen - startColor.g) * progress),
					uint8_t(startColor.b + (dimmedBlue -startColor.b) * progress)
					});
		}
	}
}

void Side::growLeft(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					((CUBE_RIGHT_X) + ((startPiece.getPosition().x) - (CUBE_RIGHT_X)) * progress),
					pieces[i][j].getPosition().y
					});

			//expand
			pieces[i][j].setScale({
					progress,
					pieces[i][j].getScale().y
					});

			//brighten
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t((dimmedRed) + (startColor.r - (startColor.r * 0.25)) * progress),
					uint8_t((dimmedGreen) + (startColor.g - (startColor.g * 0.25)) * progress),
					uint8_t((dimmedBlue) + (startColor.b - (startColor.b * 0.25)) * progress)
					});
		}
	}

}
void Side::growRight(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					((CUBE_LEFT_X) + ((startPiece.getPosition().x) - (CUBE_LEFT_X)) * progress),
					pieces[i][j].getPosition().y
					});

			//expand
			pieces[i][j].setScale({
					progress,
					pieces[i][j].getScale().y
					});

			//brighten
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t((dimmedRed) + (startColor.r - (startColor.r * 0.25)) * progress),
					uint8_t((dimmedGreen) + (startColor.g - (startColor.g * 0.25)) * progress),
					uint8_t((dimmedBlue) + (startColor.b - (startColor.b * 0.25)) * progress)
					});
		}
	}
}
void Side::growUp(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					pieces[i][j].getPosition().x,
					((CUBE_BOTTOM_Y) + ((startPiece.getPosition().y) - (CUBE_BOTTOM_Y)) * progress)
					});

			//expand
			pieces[i][j].setScale({
					pieces[i][j].getScale().x,
					progress
					});

			//brighten
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t((dimmedRed) + (startColor.r - (startColor.r * 0.25)) * progress),
					uint8_t((dimmedGreen) + (startColor.g - (startColor.g * 0.25)) * progress),
					uint8_t((dimmedBlue) + (startColor.b - (startColor.b * 0.25)) * progress)
					});
		}
	}
}
void Side::growDown(Side startSide, float progress)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			RectangleShape& startPiece = startSide.getPiece(i,j);

			//translate
			pieces[i][j].setPosition({
					pieces[i][j].getPosition().x,
					((CUBE_TOP_Y) + ((startPiece.getPosition().y) - (CUBE_TOP_Y)) * progress)
					});

			//expand
			pieces[i][j].setScale({
					pieces[i][j].getScale().x,
					progress
					});

			//brighten
			Color startColor = startPiece.getFillColor();
			uint8_t dimmedRed = startPiece.getFillColor().r * 0.25;
			uint8_t dimmedGreen = startPiece.getFillColor().g * 0.25;
			uint8_t dimmedBlue = startPiece.getFillColor().b * 0.25;
			pieces[i][j].setFillColor({
					uint8_t((dimmedRed) + (startColor.r - (startColor.r * 0.25)) * progress),
					uint8_t((dimmedGreen) + (startColor.g - (startColor.g * 0.25)) * progress),
					uint8_t((dimmedBlue) + (startColor.b - (startColor.b * 0.25)) * progress)
					});
		}
	}
}
