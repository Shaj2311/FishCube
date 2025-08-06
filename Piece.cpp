#include "Piece.h"

const Vector2f Piece::PIECE_SIZE = Vector2f(200, 200);

const Color Piece::RED = Color::Red;
const Color Piece::ORANGE = Color(255, 165, 0);
const Color Piece::GREEN = Color::Green;
const Color Piece::BLUE = Color::Blue;
const Color Piece::WHITE = Color::White;
const Color Piece::YELLOW = Color::Yellow;

void Piece::update()
{
	//change colors
	piece.setFillColor(color);
}

void Piece::draw(RenderWindow& window, int positionX, int positionY)
{
	piece.setPosition(Vector2f(positionX, positionY));
	window.draw(piece);
}

void Piece::move()
{
	static double progress = 0.f;

	if (progress >= 1.f)
	{
		progress = 0.f;
	}
}

void Piece::squish()
{
	static double progress = 0.f;

	if (progress >= 1.f)
	{
		progress = 0.f;
	}
}

void Piece::expand()
{
	static double progress = 0.f;

	if (progress >= 1.f)
	{
		progress = 0.f;
	}
}

