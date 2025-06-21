#include "Piece.h"

const Vector2f Piece::PIECE_SIZE = Vector2f(1, 1);

const Color Piece::RED = Color::Red;
const Color Piece::ORANGE = Color(255, 165, 0);
const Color Piece::GREEN = Color::Green;
const Color Piece::BLUE = Color::Blue;
const Color Piece::WHITE = Color::White;
const Color Piece::YELLOW = Color::Yellow;

void Piece::update()
{
	//change colors
}

void Piece::draw(RenderWindow& window)
{
	window.draw(piece);
}
