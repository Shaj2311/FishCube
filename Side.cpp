#include "Side.h"

const Vector2f Side::ZERO_POSITION = Vector2f(
	(1920 - 3 * Piece::PIECE_SIZE.x) / 2,
	(1080 - 3 * Piece::PIECE_SIZE.y) / 2
);

void Side::rotate(int direction)
{
	if (direction != CLOCKWISE && direction != COUNTER_CLOCKWISE) return;

	if (direction == CLOCKWISE)
	{
		for (int i = 0; i < 2; i++) //two times...
		{
			//rotate clockwise
			Piece temp = pieces[0][0];

			for (int j = 1; j < 3; j++) //move left column pieces up
			{
				pieces[j - 1][0] = pieces[j][0];
			}

			for (int j = 0; j < 2; j++) //move bottom row pieces left
			{
				pieces[2][j] = pieces[2][j + 1];
			}

			for (int j = 1; j >= 0; j--) //move right column pieces down
			{
				pieces[j + 1][2] = pieces[j][2];
			}

			for (int j = 1; j < 2; j++) //move top row pieces right
			{
				pieces[0][j + 1] = pieces[0][j];
			}

			pieces[0][1] = temp;


		}
	}


	if (direction == COUNTER_CLOCKWISE)
	{

		for (int i = 0; i < 2; i++) //two times...
		{
			//rotate counter-clockwise
			Piece temp = pieces[0][0];

			for (int j = 0; j < 2; j++) //move top row pieces left
			{
				pieces[0][j] = pieces[0][j + 1];
			}

			for (int j = 1; j < 3; j++) //move right column pieces up
			{
				pieces[j - 1][2] = pieces[j][2];
			}

			for (int j = 2; j > 0; j--) //move bottom row pieces right
			{
				pieces[2][j] = pieces[2][j - 1];
			}

			for (int j = 1; j > 0; j--) //move left column pieces down
			{
				pieces[j + 1][0] = pieces[j][0];
			}

			pieces[1][0] = temp;


		}
	}
}

void Side::update()
{
	//update pieces
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pieces[i][j].update();
		}
	}
}

void Side::draw(RenderWindow& window)
{
	//draw pieces
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pieces[i][j].draw(window, 
				ZERO_POSITION.x + (Piece::PIECE_SIZE.x * j), 
				ZERO_POSITION.y + (Piece::PIECE_SIZE.y * i)
			);
		}
	}
}

void Side::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			target.draw(pieces[i][j].getRect(), states);
}
