#ifndef SIDE_H
#define SIDE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "constants.h"
using namespace sf;
class Side
{
	//9 pieces
	RectangleShape pieces[3][3];
	Color pieceColors[3][3];

public:
	Side();
	void update(StateManager& sm);
	void draw(RenderWindow& window, StateManager& sm);

	void setPosition(double x, double y);
};
#endif
