#include "Player.h"
#include "Piece.h"
#include <iostream>

void Player::move(Vector2f targetPos)
{
	static double progress = 0.f;
	static Vector2f startingPos = fishSprite.getPosition();

	
	fishSprite.setPosition(
		startingPos.x + (targetPos.x - startingPos.x) * progress,
		startingPos.y + (targetPos.y - startingPos.y) * progress
	);
	progress += 1.f / 60;

	if (progress >= 1.f)
	{
		//reset flag
		isMoving = false;
		//reset all static vars
		startingPos = fishSprite.getPosition();
		progress = 0.f;
	}
}



Player::Player()
{

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

	fishSprite.setPosition(1920 / 2, 1080 / 2);

	fishSprite.setColor(Color::Red);

	isMoving = false;

	currentRow = currentCol = 1;
}


void Player::update()
{
	
	//Movement
	if (isMoving)
	{
		move(targetPos);
	}
	//std::cout << currentRow << "\t" << currentCol << "\n";
}

void Player::render(RenderWindow& window)
{
	window.draw(fishSprite);
}
