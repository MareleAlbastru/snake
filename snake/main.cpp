#include <fstream>
#include <iostream>
#include <cstdlib>

#include "game.hpp"

int main() {
	std::ifstream in("settings.txt");
	if (in.good() && in.peek() != std::ifstream::traits_type::eof()) {
		int dari;
		in >> dari;
		daristyle = dari;
		int boardsize;
		in >> boardsize;
		boardSize = boardsize;
		gridSize *= 16.f / boardsize;
	}
	else {
		daristyle = 0;
		boardSize = 16;
		gridSize = 50.f;
	}
	in.close();

	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(gridSize * boardSize, gridSize * boardSize), "SNAKE", sf::Style::Default, settings);
	window.setFramerateLimit(6);
	Game game(window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		game.run();
	}
	return 0;
}