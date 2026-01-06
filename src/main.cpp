#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"

int main()
{
	StateManager sm;
	sm.switchToState(IDLE_UNSOLVED);

	Game game;

	while (game.getWindow().isOpen())
	{
		game.update(sm);
		game.draw(sm);
	}
}
