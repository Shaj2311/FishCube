#ifndef SIDE_H
#define SIDE_H
#include <SFML/Graphics.hpp>
#include "constants.h"
using namespace sf;
class Side
{
	//9 pieces
	RectangleShape pieces[3][3];
	Color pieceColors[3][3];

public:
	Side();
	void update();
	void draw(RenderWindow& window);

	void setPosition(double x, double y);
};
#endif
