#ifndef GAME_H
#define GAME_H
#include "Cube.h"
#include "State.h"
#include "Player.h"
class Game
{
	RenderWindow window;
	//only one side for now
	Cube* cube;
	Player* player;

	void swapColors();

public:
	Game();
	~Game(){delete cube; delete player;}
	void pollEvents(GameState& currState, GameState& nextState);
	void update(GameState& currState, GameState& nextState);
	void draw(GameState& currState, GameState& nextState);
	
	RenderWindow& getWindow(){return window;}
};
#endif
