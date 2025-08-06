#include "Cube.h"
#include <iostream>


void Cube::rotateBackend(int direction)
{
	//update backend array
	switch (direction)
	{
	case UP:
	{
		//move sides up
		Side temp = sides[0][1];
		for (int i = 0; i < 3; i++)
		{
			sides[i][1] = sides[i + 1][1];
		}
		sides[3][1] = temp;


		//rotate left side counter-clockwise
		sides[1][0].rotate(Side::COUNTER_CLOCKWISE);

		//rotate right side clockwise
		sides[1][2].rotate(Side::CLOCKWISE);

		break;
	}
	case RIGHT:
	{
		////cycle pieces
		//Side temp = sides[3][1];
		//sides[3][1] = sides[1][0];
		//for (int i = 0; i < 2; i++)
		//{
		//	sides[1][i] = sides[1][i + 1];
		//}
		//sides[1][2] = temp;
		Side temp = sides[1][2];
		sides[1][2] = sides[1][1];
		sides[1][1] = sides[1][0];
		sides[3][1].rotate(Side::CLOCKWISE);//rotate back side before moving
		sides[3][1].rotate(Side::CLOCKWISE);
		sides[1][0] = sides[3][1];
		temp.rotate(Side::CLOCKWISE);//rotate temp side before assigning to back side
		temp.rotate(Side::CLOCKWISE);
		sides[3][1] = temp;

		//rotate top side counter-clockwise
		sides[0][1].rotate(Side::COUNTER_CLOCKWISE);

		//rotate bottom side clockwise
		sides[2][1].rotate(Side::CLOCKWISE);


		break;
	}
	case DOWN:
	{
		//move sides down
		Side temp = sides[3][1];
		for (int i = 3; i > 0; i--)
		{
			sides[i][1] = sides[i - 1][1];
		}
		sides[0][1] = temp;

		//rotate left side clockwise
		sides[1][0].rotate(Side::CLOCKWISE);

		//rotate right side counter-clockwise
		sides[1][2].rotate(Side::COUNTER_CLOCKWISE);

		break;
	}
	case LEFT:
	{
		////cycle pieces
		//Side temp = sides[3][1];
		//sides[3][1] = sides[1][2];
		//for (int i = 2; i > 0; i--)
		//{
		//	sides[1][i] = sides[1][i - 1];
		//}
		//sides[1][0] = temp;
		Side temp = sides[1][0];
		sides[1][0] = sides[1][1];
		sides[1][1] = sides[1][2];
		sides[3][1].rotate(Side::CLOCKWISE);//rotate back side before moving
		sides[3][1].rotate(Side::CLOCKWISE);
		sides[1][2] = sides[3][1];
		temp.rotate(Side::CLOCKWISE); //rotate temp side before assigning to back side
		temp.rotate(Side::CLOCKWISE);
		sides[3][1] = temp;

		//rotate top side clockwise
		sides[0][1].rotate(Side::CLOCKWISE);

		//rotate bottom side counter-clockwise
		sides[2][1].rotate(Side::COUNTER_CLOCKWISE);

		break;
	}
	default:
		break;
	}
}

Cube::Cube()
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
	for (int h = 0; h < 4; h++)
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

void Cube::update()
{
	//update sides
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//skip invalid sides
			if (j == 0 || j == 2)
			{
				if (i == 0 || i == 2 || i == 3)
					continue;
			}


			sides[i][j].update();



		}
	}

	if (isMoving)
	{
		rotate(rotationDirection);
	}
}

void Cube::draw(RenderWindow& window)
{
	getCurrentSide().draw(window); // Only draw the current face directly
}

void Cube::rotate(int direction)
{
	Side oldSide = sides[1][1];

	rotateBackend(direction);

	Side newSide = sides[1][1];

	oldSide.squish();
	newSide.expand();

}

