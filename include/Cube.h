#ifndef CUBE_H
#define CUBE_H
#include <SFML/Graphics.hpp>
#include "Side.h"
#include "State.h"
class Cube
{
	//6 sides
	Side* front;
	Side* back;
	Side* up;
	Side* down;
	Side* right;
	Side* left;

public:
	Cube();

	void update(GameState& currState, GameState& nextState);
	void draw(RenderWindow& window, GameState& currState, GameState& nextState);

	Side* getFrontSide(){return front;}
};
#endif
