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

public:
	Side();
	void update(GameState& currState, GameState& nextState);
	void draw(RenderWindow& window, GameState& currState, GameState& nextState);

	void setPosition(double x, double y);

	RectangleShape& getPiece(int row, int col){return pieces[row][col];}

	void rotateCW();
	void rotateCCW();

	void shrinkLeft(Side startSide, float progress);
	void shrinkRight(Side startSide, float progress);
	void shrinkUp(Side startSide, float progress);
	void shrinkDown(Side startSide, float progress);

	void growLeft(Side startSide, float progress);
	void growRight(Side startSide, float progress);
	void growUp(Side startSide, float progress);
	void growDown(Side startSide, float progress);
};
#endif
