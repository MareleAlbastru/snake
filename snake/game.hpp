#pragma once

#include "global.hpp"
#include "board.hpp"
#include "snake.hpp"
#include "food.hpp"

#include <cstdlib>
#include <Windows.h>

class Game {
private:
	Snake snake;
	Food apple;
	Board* board;
	sf::RenderWindow* window;
	void drawAll();
	bool ateFruit();
	void doLogic();
public:
	Game(sf::RenderWindow& otherWindow);
	void run();
	int hasEnded;
	bool paused;
};