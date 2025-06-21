#pragma once
#include "Piece.h"

class Side
{
	Piece pieces[3][3];

	bool isSolved;

public:
	Side() {}

	inline Piece& getPiece(unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 2 || indexJ > 2) return;
		return pieces[indexI][indexJ];
	}
	inline bool getIsSolved() { return isSolved; }

	
	inline void setPiece(Piece p, unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 2 || indexJ > 2) return;
		pieces[indexI][indexJ] = p;
	}
	inline void setIsSolved(bool solved) { isSolved = solved; }


	void update();
	void draw(RenderWindow& window);
};

