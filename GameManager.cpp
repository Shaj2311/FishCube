#include "GameManager.h"

void GameManager::move(int direction)
{
        Player& player = getPlayer();
        Cube& cube = getCube();

        // Get current grid tile
        int row = player.getCurrentRow();
        int col = player.getCurrentCol();

        // Predict new tile position
        int newRow = row, newCol = col;

        switch (direction)
        {
        case Player::UP:    newRow--; break;
        case Player::DOWN:  newRow++; break;
        case Player::LEFT:  newCol--; break;
        case Player::RIGHT: newCol++; break;
        }

        //Flip fish facing direction
        if (newCol > col) 
                player.getSprite().setScale(
                (Piece::PIECE_SIZE.x * 0.65) / player.getTexture().getSize().x,
                (Piece::PIECE_SIZE.y * 0.65) / player.getTexture().getSize().y
        );
        if (newCol < col)
                player.getSprite().setScale(
                -(Piece::PIECE_SIZE.x * 0.65) / player.getTexture().getSize().x,
                (Piece::PIECE_SIZE.y * 0.65) / player.getTexture().getSize().y
        );

        // If within bounds: just move
        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
        {
                player.setCurrentRow(newRow);
                player.setCurrentCol(newCol);
                Vector2f newPos = cube.getCurrentSide().getPiece(newRow, newCol).getRect().getPosition();
                player.moveTo(newPos + Piece::PIECE_SIZE / 2.f);
        }
        else
        {
                // Edge overflow: rotate cube
                cube.rotate(direction);

                // Wrap to opposite side
                if (newRow < 0) newRow = 2;
                if (newRow > 2) newRow = 0;
                if (newCol < 0) newCol = 2;
                if (newCol > 2) newCol = 0;

                player.setCurrentRow(newRow);
                player.setCurrentCol(newCol);
                Vector2f newPos = cube.getCurrentSide().getPiece(newRow, newCol).getRect().getPosition();
                player.moveTo(newPos + Piece::PIECE_SIZE / 2.f);
        }
}

void GameManager::update(double deltaTime)
{
	cube.update(deltaTime);
	player.update(deltaTime);
}

void GameManager::draw(RenderWindow& window)
{
	cube.draw(window);
	player.draw(window);
	
}
