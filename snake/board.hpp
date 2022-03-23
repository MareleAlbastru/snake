#pragma once

#include "global.hpp"

class Board {
private:
	sf::RectangleShape** board;
public:
	Board();
	~Board();
	void drawBoard(sf::RenderWindow& window);
};