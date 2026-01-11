#include "ScoreHandler.h"

ScoreHandler::ScoreHandler()
{
	moveCount = 0;
	swapCount = 0;
	timeTaken = Time::Zero;
}

void ScoreHandler::addMove(){moveCount++;}
void ScoreHandler::addSwap(){swapCount++;}
int ScoreHandler::computeFinalScore(Time timeTaken)
{
	//max score
	int score = MAX_SCORE;

	//apply swap penalty
	score -= (swapCount * SWAP_PENALTY);

	//apply move penalty
	score -= (moveCount * MOVE_PENALTY);

	//apply time penalty
	score -= int(timeTaken.asSeconds() * TIME_PENALTY);

	if(score >= 0) return score;
	return 0;
}
