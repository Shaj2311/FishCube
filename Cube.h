#pragma once
#include <cstdlib>
#include <ctime>
#include "Side.h"

class Cube
{
	//cube net
	Side sides[4][3];


	Color pieceColors[48];

public:
	
	static const int UP = 1;
	static const int RIGHT = 2;
	static const int DOWN = 3;
	static const int LEFT = 4;


	Cube()
	{
		srand(time(0));

		//initialize pieceColors array
		int index = 0;
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::WHITE;
		}
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::YELLOW;
		}
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::RED;
		}
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::ORANGE;
		}
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::BLUE;
		}
		for (int i = 0; i < 8; i++)
		{
			pieceColors[index++] = Piece::GREEN;
		}



		//randomize array using Fisher Yates
		for (int topIndex = 47; topIndex > 0; topIndex--)
		{
			//get random index
			int randomIndex = rand() % (topIndex + 1);

			//swap with top index
			Color temp = pieceColors[topIndex];
			pieceColors[topIndex] = pieceColors[randomIndex];
			pieceColors[randomIndex] = temp;
		}


		//assign center colors
		sides[0][1].getPiece(1, 1).setColor(Piece::WHITE);
		sides[1][0].getPiece(1, 1).setColor(Piece::ORANGE);
		sides[1][1].getPiece(1, 1).setColor(Piece::GREEN);
		sides[1][2].getPiece(1, 1).setColor(Piece::RED);
		sides[2][1].getPiece(1, 1).setColor(Piece::YELLOW);
		sides[3][1].getPiece(1, 1).setColor(Piece::BLUE);

		//assign colors
		int assignIndex = 0;
		for(int h = 0; h < 4; h++)
		{
			for (int i = 0; i < 3; i++)
			{
				//skip invalid side
				if (i == 0 || i == 2)
				{
					if (h != 1)
						continue;
				}



				//for each side,

				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (j == 1 && k == 1) continue; //skip center

						//for each piece,
						sides[h][i].getPiece(j, k).setColor(pieceColors[assignIndex++]);
					}
				}

			}
		}
	}


	inline void setSide(Side side, unsigned int indexI, unsigned int indexJ)
	{
		if (indexI > 3 || indexJ > 2) exit(1);

		if (
			(indexJ == 0 || indexJ == 2) &&
			(indexI != 1)
		) exit(1);


		sides[indexI][indexJ] = side;
	}


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
	void rotate(RenderWindow& window, int direction);
};

