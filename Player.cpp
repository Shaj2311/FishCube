#include "Player.h"


void Player::moveTo(Vector2f newPosition)
{
	targetPosition = newPosition;
	isMoving = true;
}

void Player::update(double deltaTime)
{
	//bobbing
	bobTime += deltaTime; 
	float offsetY = std::sin(bobTime * bobSpeed) * bobAmplitude;

	//moving
	if (isMoving)
	{
		sf::Vector2f direction = targetPosition - currentPosition;
		float distance = moveSpeed * deltaTime < std::hypot(direction.x, direction.y) ? moveSpeed * deltaTime : std::hypot(direction.x, direction.y);
		sf::Vector2f step = (direction / std::hypot(direction.x, direction.y)) * distance;

		currentPosition += step;

		if (std::hypot(targetPosition.x - currentPosition.x, targetPosition.y - currentPosition.y) < 1.f)
		{
			currentPosition = targetPosition;
			isMoving = false;
		}
	}

	fishSprite.setPosition(currentPosition.x, currentPosition.y + offsetY);

}

void Player::draw(RenderWindow& window)
{
	window.draw(fishSprite);
}

