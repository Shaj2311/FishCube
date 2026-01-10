#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Game.h"
#include "State.h"

int main()
{
	srand(time(0));

	StateManager sm;
	sm.switchToState(START);

	Game game;

	while (game.getWindow().isOpen())
	{
		GameState currState = sm.getState();
		GameState nextState = currState;

		game.update(currState, nextState);
		game.draw(currState, nextState);

		//exit
		if(nextState == EXIT) return 0;

		//switch to next state
		sm.switchToState(nextState);
	}
}
