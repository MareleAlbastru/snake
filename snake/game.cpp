#include "game.hpp"

Game::Game(sf::RenderWindow& otherWindow) {
	window = &otherWindow;
	paused = false;
	hasEnded = false;
}

void Game::drawAll() {
	window->clear();
	board.drawBoard(*window);
	apple.drawApple(*window);
	snake.drawSnake(*window);
	window->display();
}

bool Game::ateFruit() {
	if (snake.conflictsSnake(apple.getPos())) {
		return true;
	}
	return false;
}

void Game::doLogic() {
	if (GetAsyncKeyState('W') && snake.getDir() != south) snake.setDir(north);
	if (GetAsyncKeyState('S') && snake.getDir() != north) snake.setDir(south);
	if (GetAsyncKeyState('D') && snake.getDir() != west) snake.setDir(east);
	if (GetAsyncKeyState('A') && snake.getDir() != east) snake.setDir(west);

	snake.moveSnake();
	if (ateFruit()) {
		srand(time(NULL));
		snake.addTail(snake.getLastTailPos());
		apple.newApple(rand() % boardSize, rand() % boardSize);
		while (snake.conflictsSnake(apple.getPos())) {
			apple.newApple(rand() % boardSize, rand() % boardSize);
		}
	}
	if (!snake.Alive()) {
		hasEnded = true;
	}
}

void Game::run() {
	if (!hasEnded) {
		if (GetAsyncKeyState(VK_ESCAPE) & 1) { paused = !paused; }
		if (!paused) {
			doLogic();
		}
		drawAll();
	}
	else { window->close(); }
}
