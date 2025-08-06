#pragma once
#include "Piece.h"

class Side : public Drawable
{
	Piece pieces[3][3];

	bool isSolved;

public:

	static const int CLOCKWISE = 1;
	static const int COUNTER_CLOCKWISE = 2;

	static const Vector2f ZERO_POSITION;
	Side()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pieces[i][j].getRect().setPosition(Vector2f(
					ZERO_POSITION.x + (j * Piece::PIECE_SIZE.x),
					ZERO_POSITION.y + (i * Piece::PIECE_SIZE.y)
				));
			}
		}

		isSolved = false;
	}

	inline Piece& getPiece(unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 2 || indexJ > 2) exit(1);
		return pieces[indexI][indexJ];
	}
	inline bool getIsSolved() { return isSolved; }

	
	inline void setPiece(Piece p, unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 2 || indexJ > 2) exit(1);
		pieces[indexI][indexJ] = p;
	}
	inline void setIsSolved(bool solved) { isSolved = solved; }


	void rotate(int direction);
	void update();
	void draw(RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	void squish();
	void expand();
};

