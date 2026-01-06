#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "constants.h"
using namespace sf;
class Player
{
	Texture fishTexture;
	Sprite* fishSprite;

	unsigned int currentRow;
	unsigned int currentCol;

	void move(Vector2f targetPos);
public:
	Player();
	void update(GameState& currState, GameState& nextState);
	void draw(RenderWindow& window, GameState& currState, GameState& nextState);
	
};
#endif
