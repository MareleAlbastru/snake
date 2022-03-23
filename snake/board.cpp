#include "board.hpp"

Board::Board() {
	board = new sf::RectangleShape*[boardSize + 1];

	for (int i{}; i <= boardSize; ++i) {
		board[i] = new sf::RectangleShape[boardSize + 1];
	}

	for (int i{}; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			if (j % 2 == 0) {
				if (i % 2 == 0) {
					board[i][j].setSize(defSize());
					board[i][j].setFillColor(sf::Color(164, 212, 76, 200));
					board[i][j].setPosition(i * gridSize, j * gridSize);
				}
				else {
					board[i][j].setSize(defSize());
					board[i][j].setFillColor(sf::Color(160, 200, 90, 200));
					board[i][j].setPosition(i * gridSize, j * gridSize);
				}
			}
			else {
				if (i % 2 != 0) {
					board[i][j].setSize(defSize());
					board[i][j].setFillColor(sf::Color(164, 212, 76, 200));
					board[i][j].setPosition(i * gridSize, j * gridSize);
				}
				else {
					board[i][j].setSize(defSize());
					board[i][j].setFillColor(sf::Color(160, 200, 90, 200));
					board[i][j].setPosition(i * gridSize, j * gridSize);
				}
			}
		}
	}
}

Board::~Board() {
	for (int i = 0; i <= boardSize; ++i) {
		delete[] board[i];
	}
	delete[] board;
}

void Board::drawBoard(sf::RenderWindow & window) {
	for (int i{}; i < boardSize; ++i) {
		for (int j{}; j < boardSize; ++j) {
			window.draw(board[i][j]);
		}
	}

	return;
}
