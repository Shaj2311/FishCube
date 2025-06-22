#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Player
{
	Sprite fishSprite;
	Texture fishTexture;


public:

	Player()
	{
		fishSprite.setTexture(fishTexture);
	}


	inline Sprite& getPlayerSprite() { return fishSprite; }

	inline void setSprite(Sprite playerSprite) { fishSprite = playerSprite; }

	void update();
	void draw(RenderWindow& window);
	
};

