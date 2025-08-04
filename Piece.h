#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Piece
{
private:
	RectangleShape piece;
	Color color;


public:

	static const Vector2f PIECE_SIZE;

	static const Color RED;
	static const Color ORANGE;
	static const Color GREEN;
	static const Color BLUE;
	static const Color WHITE;
	static const Color YELLOW;
	

	Piece()
	{
		piece.setFillColor(color);
		//piece.setOutlineColor(Color::Black);
		//piece.setOutlineThickness(10);
		piece.setSize(PIECE_SIZE);   
	}

	inline void setColor(Color pieceColor)
	{
		if	(
			pieceColor != RED &&
			pieceColor != ORANGE &&
			pieceColor != GREEN &&
			pieceColor != BLUE &&
			pieceColor != WHITE &&
			pieceColor != YELLOW
			)
		{
			return;
		}

		color = pieceColor;
	}
	inline void setPiece(RectangleShape otherPiece) { piece = otherPiece; }


	inline Color getColor() { return color; }
	inline RectangleShape& getRect() { return piece; }
	inline const RectangleShape& getRect() const { return piece; }


	void update();
	void draw(RenderWindow& window, int positionX, int positionY);
};

