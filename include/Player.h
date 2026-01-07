#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Constants.h"
#include "Direction.h"

using namespace sf;
class Player
{
	Texture fishTexture;
	Sprite* fishSprite;

	unsigned int currentRow;
	unsigned int currentCol;

	double moveProgress = 0.f;
	Direction direction;

	void move(Vector2f targetPos);
public:
	Player();
	void update(GameState& currState, GameState& nextState);
	void draw(RenderWindow& window, GameState& currState, GameState& nextState);
	
	Direction getDirection(){return direction;}
	void setDirection(Direction newDirection){direction = newDirection;}

	unsigned int getRow(){return currentRow;}
	unsigned int getCol(){return currentCol;}
	
};
#endif
