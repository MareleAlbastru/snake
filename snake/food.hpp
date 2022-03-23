#pragma once

#include "global.hpp"

class Food {
private:
	sf::RectangleShape apple;
public:
	Food();
	void newApple(float x, float y);
	void drawApple(sf::RenderWindow& window);
	sf::Vector2<float> getPos() { return apple.getPosition(); }
};