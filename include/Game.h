#ifndef GAME_H
#define GAME_H
#include "Side.h"
class Game
{
	RenderWindow window;
	//only one side for now
	Side s;
public:
	Game();
	void pollEvents();
	void update();
	void draw();
	
	RenderWindow& getWindow(){return window;}
};
#endif
