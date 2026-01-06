#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
	Texture fishTexture;
	Sprite fishSprite;

	Vector2f targetPos;
	bool isMoving;

	unsigned int currentRow;
	unsigned int currentCol;

	void move(Vector2f targetPos);

public:
	Player();
	
};
#endif
