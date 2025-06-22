#include "GameManager.h"

void GameManager::update()
{
	cube.update();
	player.update();
}

void GameManager::draw(RenderWindow& window)
{
	cube.draw(window);
	player.draw(window);
	
}
