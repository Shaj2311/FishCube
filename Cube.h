#pragma once
#include <cstdlib>
#include <ctime>
#include "Side.h"

class Cube
{
	//cube net
	Side sides[4][3];

	Color pieceColors[48];


	bool isMoving = false;
	unsigned int rotationDirection;
	void rotateBackend(int direction);

public:
	
	static const int UP = 1;
	static const int RIGHT = 2;
	static const int DOWN = 3;
	static const int LEFT = 4;


	Cube();


	inline void setSide(Side side, unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 3 || indexJ > 2) exit(1);

		if (
			(indexJ == 0 || indexJ == 2) &&
			(indexI != 1)
		) exit(1);


		sides[indexI][indexJ] = side;
	}
	inline void setRotationDirection(unsigned int direction)
	{
		if (direction > 4) exit(1);
		rotationDirection = direction;
	}
	inline void setIsMoving(bool moving) { isMoving = moving; }

	inline Side& getSide(unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 3 || indexJ > 2) exit(1);

		if (
			(indexJ == 0 || indexJ == 2) &&
			(indexI != 1)
			) exit(1);

		if (indexI > 3 || indexJ > 2) exit(1);
		return sides[indexI][indexJ];
	}

	inline Side& getCurrentSide() { return sides[1][1]; }
	

	void update();
	void draw(RenderWindow& window);
	void rotate(int direction);


};

