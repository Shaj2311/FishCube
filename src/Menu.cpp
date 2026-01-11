#include "Menu.h"
void drawMenu(RenderWindow& window, GameState& currState, unsigned int* finalScore, unsigned int* highScore)
{
	switch(currState)
	{
		case START:
			{
				//Intro Text
				Font titleFont("assets/fonts/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "FISHCUBE", 150);

				//other text
				Font otherFont("assets/fonts/Roboto-Black.ttf");
				Text startText(otherFont, "PRESS [ENTER] TO START", 50);
				Text quitText(otherFont, "PRESS [Q] TO QUIT", 50);

				titleText.setFillColor(Color::White);
				startText.setFillColor(Color::White);
				quitText.setFillColor(Color::White);

				FloatRect titleBounds = titleText.getLocalBounds();
				FloatRect startBounds = startText.getLocalBounds();
				FloatRect quitBounds = quitText.getLocalBounds();

				titleText.setOrigin({
						(titleBounds.position.x + titleBounds.size.x) / 2,
						(titleBounds.position.y + titleBounds.size.y) / 2
						});
				startText.setOrigin({
						(startBounds.position.x + startBounds.size.x) / 2,
						(startBounds.position.y + startBounds.size.y) / 2
						});
				quitText.setOrigin({
						(quitBounds.position.x + quitBounds.size.x) / 2,
						(quitBounds.position.y + quitBounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});
				startText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f});
				quitText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 80});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);
				window.draw(startText);
				window.draw(quitText);

				break;
			}
		case IDLE_UNSOLVED_PAUSED:
		case MOVING_UNSOLVED_PAUSED:
		case IDLE_SOLVED_PAUSED:
		case MOVING_SOLVED_PAUSED:
			{
				//Intro Text
				Font titleFont("assets/fonts/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "PAUSED", 150);

				//other text
				Font otherFont("assets/fonts/Roboto-Black.ttf");
				Text resumeText(otherFont, "PRESS [ESC] TO RESUME", 50);
				Text returnText(otherFont, "PRESS [Q] TO RETURN TO MAIN MENU", 50);
				Text restartText(otherFont, "PRESS [R] TO RESTART", 50);

				titleText.setFillColor(Color::White);
				resumeText.setFillColor(Color::White);
				returnText.setFillColor(Color::White);
				restartText.setFillColor(Color::White);

				FloatRect titleBounds = titleText.getLocalBounds();
				FloatRect resumeBounds = resumeText.getLocalBounds();
				FloatRect returnBounds = returnText.getLocalBounds();
				FloatRect restartBounds = restartText.getLocalBounds();

				titleText.setOrigin({
						(titleBounds.position.x + titleBounds.size.x) / 2,
						(titleBounds.position.y + titleBounds.size.y) / 2
						});
				resumeText.setOrigin({
						(resumeBounds.position.x + resumeBounds.size.x) / 2,
						(resumeBounds.position.y + resumeBounds.size.y) / 2
						});
				returnText.setOrigin({
						(returnBounds.position.x + returnBounds.size.x) / 2,
						(returnBounds.position.y + returnBounds.size.y) / 2
						});
				restartText.setOrigin({
						(restartBounds.position.x + restartBounds.size.x) / 2,
						(restartBounds.position.y + restartBounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});
				resumeText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f});
				returnText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 80});
				restartText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 80 + 80});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);
				window.draw(resumeText);
				window.draw(returnText);
				window.draw(restartText);

				break;
			}
		case WIN:
			{

				//Intro Text
				Font titleFont("assets/fonts/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "YOU WIN", 150);
				Text scoreText(
						titleFont, 
						std::string("Score: " + std::to_string(*finalScore)),
						80
					      );
				Text highScoreText(
						titleFont, 
						std::string("High Score: " + std::to_string(*highScore)),
						70
					      );
				Text newHighText(
						titleFont,
						"New High Score!",
						40
						);

				//other text
				Font otherFont("assets/fonts/Roboto-Black.ttf");
				Text resumeText(otherFont, "PRESS [ENTER] TO ENTER EXPLORE MODE", 50);
				Text returnText(otherFont, "PRESS [Q] TO RETURN TO MAIN MENU", 50);
				Text restartText(otherFont, "PRESS [R] TO RESTART", 50);

				titleText.setFillColor(Color::White);
				scoreText.setFillColor(Color::White);
				highScoreText.setFillColor(Color::White);
				newHighText.setFillColor(Color::White);
				resumeText.setFillColor(Color::White);
				returnText.setFillColor(Color::White);
				restartText.setFillColor(Color::White);

				FloatRect titleBounds = titleText.getLocalBounds();
				FloatRect scoreBounds = scoreText.getLocalBounds();
				FloatRect highScoreBounds = highScoreText.getLocalBounds();
				FloatRect newHighBounds = newHighText.getLocalBounds();
				FloatRect resumeBounds = resumeText.getLocalBounds();
				FloatRect returnBounds = returnText.getLocalBounds();
				FloatRect restartBounds = restartText.getLocalBounds();

				titleText.setOrigin({
						(titleBounds.position.x + titleBounds.size.x) / 2,
						(titleBounds.position.y + titleBounds.size.y) / 2
						});
				scoreText.setOrigin({
						(scoreBounds.position.x + scoreBounds.size.x) / 2,
						(scoreBounds.position.y + scoreBounds.size.y) / 2
						});
				highScoreText.setOrigin({
						(highScoreBounds.position.x + highScoreBounds.size.x) / 2,
						(highScoreBounds.position.y + highScoreBounds.size.y) / 2
						});
				newHighText.setOrigin({
						(newHighBounds.position.x + newHighBounds.size.x) / 2,
						(newHighBounds.position.y + newHighBounds.size.y) / 2
						});
				resumeText.setOrigin({
						(resumeBounds.position.x + resumeBounds.size.x) / 2,
						(resumeBounds.position.y + resumeBounds.size.y) / 2
						});
				returnText.setOrigin({
						(returnBounds.position.x + returnBounds.size.x) / 2,
						(returnBounds.position.y + returnBounds.size.y) / 2
						});
				restartText.setOrigin({
						(restartBounds.position.x + restartBounds.size.x) / 2,
						(restartBounds.position.y + restartBounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f - 200});
				scoreText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});
				highScoreText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f + 200});
				if(*highScore == *finalScore)
					newHighText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f + 200 + 150});
				resumeText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 100});
				returnText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 100 + 80});
				restartText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f + 100 + 80 + 80});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);
				window.draw(scoreText);
				window.draw(highScoreText);
				window.draw(newHighText);
				window.draw(resumeText);

				window.draw(returnText);
				window.draw(restartText);

				break;
			}
		case EXIT_CONFIRM:
			{
				//Intro Text
				Font titleFont("assets/fonts/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "FISHCUBE", 150);

				//other text
				Font otherFont("assets/fonts/Roboto-Black.ttf");
				Text confirmText(otherFont, "ARE YOU SURE YOU WANT TO QUIT? [Y/N]", 50);

				titleText.setFillColor(Color::White);
				confirmText.setFillColor(Color::White);

				FloatRect titleBounds = titleText.getLocalBounds();
				FloatRect resumeBounds = confirmText.getLocalBounds();

				titleText.setOrigin({
						(titleBounds.position.x + titleBounds.size.x) / 2,
						(titleBounds.position.y + titleBounds.size.y) / 2
						});
				confirmText.setOrigin({
						(resumeBounds.position.x + resumeBounds.size.x) / 2,
						(resumeBounds.position.y + resumeBounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});
				confirmText.setPosition({WINDOW_WIDTH/2.f, 2*WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);
				window.draw(confirmText);

				break;
			}
	}
}
