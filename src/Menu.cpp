#include "Menu.h"
void drawMenu(RenderWindow& window, GameState& currState)
{
	switch(currState)
	{
		case START:
			{
				//Intro Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "FISHCUBE", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case IDLE_UNSOLVED_PAUSED:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "PAUSED", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case MOVING_UNSOLVED_PAUSED:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "PAUSED", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case IDLE_SOLVED_PAUSED:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "PAUSED", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case MOVING_SOLVED_PAUSED:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "PAUSED", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case WIN:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "YOU WIN", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
		case EXIT:
			{
				//Paused Text
				Font titleFont("assets/PressStart2P-Regular.ttf");
				Text titleText(titleFont, "YOU SURE, BRUH?", 150);

				titleText.setFillColor(Color::White);

				FloatRect bounds = titleText.getLocalBounds();
				titleText.setOrigin({
						(bounds.position.x + bounds.size.x) / 2,
						(bounds.position.y + bounds.size.y) / 2
						});

				titleText.setPosition({WINDOW_WIDTH/2.f, WINDOW_HEIGHT/3.f});


				//Background
				RectangleShape background({WINDOW_WIDTH, WINDOW_HEIGHT});
				background.setFillColor(Color::Blue);


				//render
				window.draw(background);
				window.draw(titleText);

				break;
			}
	}
}
