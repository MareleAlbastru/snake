#pragma once

#include <vector>

#include "global.hpp"

enum direction {
	stop = 0,
	north = 1,
	east = 2,
	south = 3,
	west = 4,
};

class Snake {
private:
	int dir;
	int tailLenght;
	sf::RectangleShape head;
	std::vector<sf::RectangleShape> tail;
	float offsetX, offsetY, offsetDariusX, offsetDariusY;
	bool isAlive;
	bool outOfBounds();
	void isDie();
public:
	Snake();
	void addTail(sf::Vector2<float> pos);
	void moveSnake();
	void setDir(int newDir);
	void drawSnake(sf::RenderWindow& window);
	int getDir() const { return dir; }
	bool conflictsSnake(sf::Vector2<float> pos);
	bool Alive() const { return isAlive; }
	sf::Vector2<float> getLastTailPos() { return tail[tailLenght - 1].getPosition(); }
};