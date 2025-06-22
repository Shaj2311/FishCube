#pragma once
#include "Cube.h"
#include "Player.h"


class GameManager
{
	Cube cube;
	Player player;

public:

	inline Cube& getCube() { return cube; }
	inline Player& getPlayer() { return player; }


	inline void setCube(Cube cube) { this->cube = cube; }
	inline void setPlayer(Player player) { this->player = player; }


	void update();
	void draw(RenderWindow& window);


};