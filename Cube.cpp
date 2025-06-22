#include "Cube.h"

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
}

void Cube::draw(RenderWindow& window)
{
	//draw current side
	sides[1][1].draw(window);
}

void Cube::rotate(RenderWindow& window, int direction)
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
		//cycle pieces
		Side temp = sides[3][1];
		sides[3][1] = sides[1][0];
		for (int i = 0; i < 2; i++)
		{
			sides[1][i] = sides[1][i + 1];
		}
		sides[1][2] = temp;
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
		//cycle pieces
		Side temp = sides[3][1];
		sides[3][1] = sides[1][2];
		for (int i = 2; i > 0; i--)
		{
			sides[1][i] = sides[1][i - 1];
		}
		sides[1][0] = temp;
		break;
	}
	default:
		break;
	}

}
