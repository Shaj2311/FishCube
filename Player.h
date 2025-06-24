#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Piece.h"
using namespace sf;

class Player
{
	Sprite fishSprite;
	Texture fishTexture;

	Vector2f currentPosition;
	Vector2f targetPosition;

	int currentRow;
	int currentCol;

	bool isMoving = false;
	double moveSpeed = 500;


	double bobTime = 0.f;        
	double bobAmplitude = 10.f;
	double bobSpeed = 3.f;       

public:

	static const int UP = 1;
	static const int RIGHT = 2;
	static const int DOWN = 3;
	static const int LEFT = 4;

	Player()
	{
		currentRow = 1;
		currentCol = 1;

		fishTexture.loadFromFile("fish.png");
		fishSprite.setTexture(fishTexture);
			

		fishSprite.setOrigin(
			fishTexture.getSize().x / 2,
			fishTexture.getSize().y / 2
		);

		fishSprite.setScale(
			(Piece::PIECE_SIZE.x * 0.65) / fishTexture.getSize().x,
			(Piece::PIECE_SIZE.y * 0.65) / fishTexture.getSize().y
			);


	}


	inline Sprite& getSprite() { return fishSprite; }
	inline Texture& getTexture() { return fishTexture; }
	inline double getBobTime() { return bobTime; }
	inline double getBobAmplitude() { return bobAmplitude; }
	inline double getBobSpeed() { return bobSpeed; }
	inline Vector2f getCurrentPosition() { return currentPosition; }
	inline Vector2f getTargetPosition() { return targetPosition; }
	inline bool getIsMoving() { return isMoving; }
	inline int getCurrentRow() { return currentRow; }
	inline int getCurrentCol() { return currentCol; }
	

	inline void setSprite(Sprite playerSprite) { fishSprite = playerSprite; }
	inline void setTexture(Texture playerTexture) { fishTexture = playerTexture; }
	inline void setCurrentPosition(Vector2f position) { currentPosition = position; }
	inline void setTargetPosition(Vector2f position) { targetPosition = position; }
	inline void setIsMoving(bool moving) { isMoving = moving; }
	inline void setCurrentRow(unsigned int row) 
	{
		if (row > 2) exit(1);
		currentRow = row; 
	}
	inline void setCurrentCol(unsigned int col) 
	{ 
		if (col > 2) exit(1);
		currentCol = col; 
	}

	void moveTo(Vector2f newPosition);
	void update(double updateTime);
	void draw(RenderWindow& window);
	
};

