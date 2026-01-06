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

void Side::update()
{
	//update colors
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			pieces[i][j].setFillColor(pieceColors[i][j]);
		}
	}
}
void Side::draw(RenderWindow& window)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			window.draw(pieces[i][j]);
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
