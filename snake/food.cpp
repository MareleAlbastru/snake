#include "food.hpp"

Food::Food() {
	apple.setFillColor(sf::Color::Red);
	apple.setPosition(defPos(boardSize - boardSize / 4.f, boardSize / 2.f));
	apple.setSize(defSize());
}

void Food::newApple(float x, float y) {
	apple.setPosition(defPos(x, y));

	return;
}

void Food::drawApple(sf::RenderWindow& window) {
	window.draw(apple);

	return;
}