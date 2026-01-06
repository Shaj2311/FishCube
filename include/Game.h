#ifndef GAME_H
#define GAME_H
#include "Side.h"
#include "State.h"
#include "Player.h"
class Game
{
	RenderWindow window;
	//only one side for now
	Side* s;
	Player* p;
public:
	Game();
	~Game(){delete s;}
	void pollEvents(GameState& currState, GameState& nextState);
	void update(GameState& currState, GameState& nextState);
	void draw(GameState& currState, GameState& nextState);
	
	RenderWindow& getWindow(){return window;}
};
#endif
