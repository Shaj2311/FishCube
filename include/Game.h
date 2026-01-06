#ifndef GAME_H
#define GAME_H
#include "Side.h"
#include "State.h"
class Game
{
	RenderWindow window;
	//only one side for now
	Side s;
public:
	Game();
	void pollEvents(StateManager& sm);
	void update(StateManager& sm);
	void draw(StateManager& sm);
	
	RenderWindow& getWindow(){return window;}
};
#endif
