#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	Texture fishTexture;
	Sprite fishSprite;

	Vector2f targetPos;
	bool isMoving;

	unsigned int currentRow;
	unsigned int currentCol;

	void move(Vector2f targetPos);
	
public:
	Player();

	void setIsMoving(bool moving) { isMoving = moving; }
	void setTargetPos(Vector2f target) { targetPos = target; }
	void incrementRow() { currentRow++; }
	void incrementCol() { currentCol++; }
	void decrementRow() { currentRow--; }
	void decrementCol() { currentCol--; }

	bool getIsMoving() { return isMoving; }
	Vector2f getCurrentPos() { return fishSprite.getPosition(); }
	int getRow() { return currentRow; }
	int getCol() { return currentCol; }
	Color getColor() { return fishSprite.getColor(); }

	void update();
	void render(RenderWindow& window);
	
	
};

