#include "snake.hpp"

Snake::Snake() {
	dir = 0;
	tailLenght = 0;
	isAlive = true;

	offsetX = 0;
	offsetY = 0;
	offsetDariusX = 0;
	offsetDariusY = 0;
	
	head.setPosition(defPos(boardSize / 4.f, boardSize / 2.f));
	head.setSize(defSize());
	head.setFillColor(sf::Color::Blue);

	addTail(defPos((boardSize / 4.f) - 1.f, boardSize / 2.f));
	addTail(defPos((boardSize / 4.f) - 2.f, boardSize / 2.f));

	return;
}

void Snake::addTail(sf::Vector2<float> pos) {
	tail.push_back(sf::RectangleShape(defSize()));
	++tailLenght;
	sf::RectangleShape& tailPart = tail.back();
	tailPart.setPosition(pos);
	tailPart.setFillColor(sf::Color::Cyan);	

	return;
}

bool Snake::outOfBounds() {;
	if (head.getPosition().x < 0.f * gridSize or head.getPosition().x >= boardSize * gridSize) return true;
	if (head.getPosition().y < 0.f * gridSize or head.getPosition().y >= boardSize * gridSize) return true;
	return false;
}

void Snake::isDie() {
	for (sf::RectangleShape itr : tail) {
		if (head.getPosition() == itr.getPosition()) {
			isAlive = false;
			head.move(-offsetX, -offsetY);
			return;
		}
	}
	return;
}

void Snake::moveSnake() {
	if (dir == stop) return;
	sf::Vector2<float> lastPos = head.getPosition();
	head.move(offsetX, offsetY);
	isDie();
	if (isAlive) {
		if (outOfBounds()) {
			if (daristyle) {
				head.setPosition(sf::Vector2<float>(offsetDariusX, offsetDariusY));
			}
			else {
				isAlive = false;
				head.move(-offsetX, -offsetY);
				return;
			}
		}
		for (int i{}; i < tailLenght; ++i) {
			sf::Vector2<float> lastTailPos = tail[i].getPosition();
			tail[i].setPosition(lastPos);
			lastPos = lastTailPos;
		}
		return;
	}
}

void Snake::setDir(int newDir) {
	dir = newDir;
	switch (dir) {
	case north:
		offsetX = 0.f;
		offsetY = -gridSize;
		if (daristyle) {
			offsetDariusX = head.getPosition().x;
			offsetDariusY = (boardSize - 1) * gridSize;
		}
		break;
	case south:
		offsetX = 0.f;
		offsetY = gridSize;
		if (daristyle) {
			offsetDariusX = head.getPosition().x;
			offsetDariusY = 0.f * gridSize;
		}
		break;
	case west:
		offsetX = -gridSize;
		offsetY = 0.f;
		if (daristyle) {
			offsetDariusX = (boardSize - 1) * gridSize;
			offsetDariusY = head.getPosition().y;
		}
		break;
	case east:
		offsetX = gridSize;
		offsetY = 0.f;
		if (daristyle) {
			offsetDariusX = 0.f;
			offsetDariusY = head.getPosition().y;
		}
		break;
	}
	return;
}

void Snake::drawSnake(sf::RenderWindow& window) {
	window.draw(head);
	for (sf::RectangleShape itr : tail) {
		window.draw(itr);
	}

	return;
}

bool Snake::conflictsSnake(sf::Vector2<float> pos) {
	if (head.getPosition() == pos) {
		return true;
	}
	for (sf::RectangleShape itr : tail) {
		if (itr.getPosition() == pos) {
			return true;
		}
	}
	return false;
}
