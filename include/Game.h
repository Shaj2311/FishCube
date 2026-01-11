#ifndef GAME_H
#define GAME_H
#include "Cube.h"
#include "State.h"
#include "Player.h"
#include "Menu.h"
#include "ScoreHandler.h"
class Game
{
	RenderWindow window;
	Cube* cube;
	Player* player;
	Clock clock;
	Font uiFont;
	Text* timerText;
	Text* pauseText;
	ScoreHandler score;
	unsigned int finalScore;


	void swapColors();
	void updateTimerText();

public:
	Game();
	~Game(){delete cube; delete player;}
	void pollEvents(GameState& currState, GameState& nextState);
	void update(GameState& currState, GameState& nextState);
	void draw(GameState& currState, GameState& nextState);
	
	RenderWindow& getWindow(){return window;}

	bool isValidMove(Direction dir);
};
#endif
