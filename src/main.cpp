#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"

int main()
{
	StateManager sm;
	sm.switchToState(START);

	Game game;

	while (game.getWindow().isOpen())
	{
		GameState currState = sm.getState();
		GameState nextState = currState;

		game.update(currState, nextState);
		game.draw(currState, nextState);

		sm.switchToState(nextState);
	}
}
