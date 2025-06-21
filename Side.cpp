#include "Side.h"

void Side::update()
{
	//update pieces
}

void Side::draw(RenderWindow& window)
{
	//draw pieces
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			pieces[i][j].draw(window);
		}
	}
}
