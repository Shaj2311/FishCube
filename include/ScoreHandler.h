#ifndef SCORE_H
#define SCORE_H
#include <SFML/System.hpp>
#include <fstream>
#include "constants.h"
using namespace sf;
class ScoreHandler
{
	int moveCount;
	int swapCount;
	Time timeTaken;

public:
	ScoreHandler();
	void addMove();
	void addSwap();
	int computeFinalScore(Time timeTaken);
	int getHighScore();
};
#endif
