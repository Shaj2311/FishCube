#pragma once
#include "Cube.h"
#include "Player.h"


class GameManager
{
	Cube cube;
	Player player;

public:
	GameManager()
	{

		player.setCurrentPosition(cube.getCurrentSide().getPiece(1, 1).getRect().getPosition() + Piece::PIECE_SIZE / 2.f);
		player.setTargetPosition(player.getCurrentPosition());
		player.getSprite().setPosition(player.getCurrentPosition());



	/*	player.getSprite().setPosition(
			cube.getCurrentSide().getPiece(1,1).getRect().getPosition() + Piece::PIECE_SIZE / 2.f
		);*/

		player.getSprite().setColor(
			Piece::BLUE
		);
		
	}

	inline Cube& getCube() { return cube; }
	inline Player& getPlayer() { return player; }


	inline void setCube(Cube cube) { this->cube = cube; }
	inline void setPlayer(Player player) { this->player = player; }


	void move(int direction);
	void update(double deltaTime);
	void draw(RenderWindow& window);


};