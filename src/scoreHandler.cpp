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

	//write to file if higher than high score
	if(score > this->getHighScore())
	{
		std::fstream highScoreFile("save/highScore.dat", std::ios::out);
		highScoreFile << std::to_string(score);
		highScoreFile.close();
	}

	if(score >= 0) return score;
	return 0;
}
int ScoreHandler::getHighScore()
{
	std::filesystem::create_directory("save");
	std::fstream highScoreFile("save/highScore.dat", std::ios::in | std::ios::out);
	//make file and write 0 if file doesn't exist
	if(!highScoreFile.is_open())
	{
		std::ofstream writeFile("save/highScore.dat");
		writeFile << "0";
		writeFile.close();

		highScoreFile.open("save/highScore.dat", std::ios::in | std::ios::out);
	}

	//get high score
	std::string highScoreStr;
	std::getline(highScoreFile, highScoreStr);
	highScoreFile.close();

	//return integer value
	return std::stoi(highScoreStr);
}
