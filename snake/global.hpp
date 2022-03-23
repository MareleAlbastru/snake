#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

inline int boardSize = 16;

inline float gridSize = 50.f;

inline sf::Vector2<float> defSize() {
	return sf::Vector2<float>(gridSize, gridSize);
}
inline sf::Vector2<float> defPos(float x, float y) {
	return sf::Vector2<float>(x * gridSize, y * gridSize);
}

inline bool daristyle = true;