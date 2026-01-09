#ifndef CUBE_H
#define CUBE_H
#include <SFML/Graphics.hpp>
#include "Side.h"
#include "State.h"
#include "Direction.h"
class Cube
{
	//6 sides
	Side* front;
	Side* back;
	Side* up;
	Side* down;
	Side* right;
	Side* left;

	Color* initColors();

public:
	Cube();

	void update(GameState& currState, GameState& nextState);
	void draw(RenderWindow& window, GameState& currState, GameState& nextState, Direction dir);

	void rotateRight(GameState& currState, GameState& nextState);
	void rotateLeft(GameState& currState, GameState& nextState);
	void rotateUp(GameState& currState, GameState& nextState);
	void rotateDown(GameState& currState, GameState& nextState);

	Side* getFrontSide(){return front;}
	Side* getBackSide(){return back;}
	Side* getLeftSide(){return left;}
	Side* getRightSide(){return right;}
	Side* getUpSide(){return up;}
	Side* getDownSide(){return down;}
};
#endif
