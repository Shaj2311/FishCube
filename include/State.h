#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

using namespace sf;

enum GameState
{
	START,
	GAME_START,

	IDLE_UNSOLVED,
	IDLE_UNSOLVED_PAUSED,


	MOVING_UNSOLVED,
	MOVING_UNSOLVED_PAUSED,

	IDLE_SOLVED,
	IDLE_SOLVED_PAUSED,

	MOVING_SOLVED,
	MOVING_SOLVED_PAUSED,

	WIN,
	EXIT_CONFIRM,
	EXIT
};

class StateManager
{
	GameState gameState;
public:
	GameState getState(){return gameState;}
	void switchToState(GameState newState);
};

#endif
