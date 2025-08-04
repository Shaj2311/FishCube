#include "Game.h"

int main()
{

        Game game;




        //Game Loop
        while(game.getWindow()->isOpen())
        {

                //Update
                game.update();

                //Render
                game.render();
        }

        return 0;
}