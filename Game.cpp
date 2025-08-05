#include "Game.h"

void Game::pollEvents()
{
        //Event Polling
        sf::Event event;
        while (window->pollEvent(event))
        {
                switch (event.type)
                {

                case Event::Closed:
                        window->close();
                        break;



                //Keyboard Inputs
                case Event::KeyPressed:
                        switch (event.key.code)
                        {
                        case Keyboard::Escape:
                                window->close();
                                break;

                        case Keyboard::Right:
                                if (player.getIsMoving()) break; //do not accept input if player is already moving
                                player.setIsMoving(true);
                                if (player.getCol() < 2)
                                {
                                        if (cube.getCurrentSide().getPiece(player.getRow(), player.getCol() + 1).getColor() == player.getColor()) //do not move if same color
                                        {
                                                player.setIsMoving(false);
                                                break;
                                        }


                                        //move one step right
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x + Piece::PIECE_SIZE.x,
                                                player.getCurrentPos().y
                                        ));

                                        player.incrementCol();
                                }
                                else
                                {
                                        if (cube.getCurrentSide().getPiece(player.getRow(), player.getCol() - 2).getColor() == player.getColor()) break; //do not move if same color

                                        //move 2 steps left
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x - (2 * Piece::PIECE_SIZE.x),
                                                player.getCurrentPos().y
                                        ));

                                        player.decrementCol(); player.decrementCol();
                                }
                                break;

                        case Keyboard::Left:
                                if (player.getIsMoving()) break; //do not accept input if player is already moving
                                player.setIsMoving(true);
                                if (player.getCol() > 0)
                                {

                                        if (cube.getCurrentSide().getPiece(player.getRow(), player.getCol() - 1).getColor() == player.getColor()) //do not move if same color
                                        {
                                                player.setIsMoving(false);
                                                break;
                                        }

                                        //move one step left
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x - Piece::PIECE_SIZE.x,
                                                player.getCurrentPos().y
                                        ));

                                        player.decrementCol();
                                }
                                else
                                {

                                        if (cube.getCurrentSide().getPiece(player.getRow(), player.getCol() + 2).getColor() == player.getColor()) break; //do not move if same color

                                        //move 2 steps right
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x + (2 * Piece::PIECE_SIZE.x),
                                                player.getCurrentPos().y
                                        ));

                                        player.incrementCol(); player.incrementCol();
                                }
                                break;

                        case Keyboard::Up:
                                if (player.getIsMoving()) break; //do not accept input if player is already moving
                                player.setIsMoving(true);
                                if (player.getRow() > 0)
                                {

                                        if (cube.getCurrentSide().getPiece(player.getRow() - 1, player.getCol()).getColor() == player.getColor())//do not move if same color
                                        {
                                                player.setIsMoving(false);
                                                break;
                                        }

                                        //move one step up
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x ,
                                                player.getCurrentPos().y - Piece::PIECE_SIZE.y
                                        ));

                                        player.decrementRow();
                                }
                                else
                                {

                                        if (cube.getCurrentSide().getPiece(player.getRow() + 2, player.getCol()).getColor() == player.getColor()) break; //do not move if same color

                                        //move 2 steps down
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x ,
                                                player.getCurrentPos().y + (2 * Piece::PIECE_SIZE.y)
                                        ));

                                        player.incrementRow(); player.incrementRow();
                                }
                                break;

                        case Keyboard::Down:
                                if (player.getIsMoving()) break; //do not accept input if player is already moving
                                player.setIsMoving(true);

                                if (player.getRow() < 2)
                                {
                                        if (cube.getCurrentSide().getPiece(player.getRow() + 1, player.getCol()).getColor() == player.getColor())//do not move if same color
                                        {
                                                player.setIsMoving(false);
                                                break;
                                        }

                                        //move one step down
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x ,
                                                player.getCurrentPos().y + Piece::PIECE_SIZE.y
                                        ));

                                        player.incrementRow();
                                }
                                else
                                {
                                        if (cube.getCurrentSide().getPiece(player.getRow() - 2, player.getCol()).getColor() == player.getColor()) break; //do not move if same color

                                        //move 2 steps up
                                        player.setTargetPos(Vector2f(
                                                player.getCurrentPos().x,
                                                player.getCurrentPos().y - (2 * Piece::PIECE_SIZE.y)
                                        ));

                                        player.decrementRow(); player.decrementRow();
                                }
                                break;
                        }
                }
        }
}

Game::Game()
{
	vMode = vMode.getFullscreenModes()[0];
	window = new RenderWindow(vMode, "FishCube");
        window->setFramerateLimit(60);

}

Game::~Game()
{
	delete window;
}

void Game::update()
{
        pollEvents();

        //Update
        cube.update();
        player.update();
}

void Game::render()
{
        window->clear();

        //DRAW
        cube.draw(*window);
        player.render(*window);

        window->display();
}
