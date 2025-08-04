#pragma once

#include "Cube.h"
#include "Player.h"
using namespace sf;


class Game
{
private:
	RenderWindow* window = nullptr;
	VideoMode vMode;
	Event event;

	Cube cube;
	Player player;

	void pollEvents();


public:
	//Constructors & Destructors
	Game();
	~Game();

	//Getters
	RenderWindow* getWindow() { return window; }
	VideoMode& getVideoMode() { return vMode; }


	//Functions
	void update();
	void render();
};

