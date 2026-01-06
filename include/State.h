#ifndef STATE_H
#define STATE_H

enum GameState
{
	START,
	GAME_START,

	IDLE_UNSOLVED,
	IDLE_UNSOLVED_PAUSED,

	MOVING_UNSOLVED,
	MOVING_UNSOLVED_PAUSED,

	IDLE_SOLVED,
	IDLE_SOLVED_PAUSE,

	MOVING_SOLVED,
	MOVING_SOLVED_PAUSE,

	WIN,
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
