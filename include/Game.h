#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
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
	unsigned int highScore;
	SoundBuffer popBuf;

	SoundBuffer clickBuf;
	Sound* pop;
	Sound* click;



	void swapColors();
	void updateTimerText();

public:
	Game();
	~Game();
	void pollEvents(GameState& currState, GameState& nextState);
	void update(GameState& currState, GameState& nextState);
	void draw(GameState& currState, GameState& nextState);
	
	RenderWindow& getWindow(){return window;}

	bool isValidMove(Direction dir);
};
#endif
