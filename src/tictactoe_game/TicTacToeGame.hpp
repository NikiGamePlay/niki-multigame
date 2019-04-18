#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "TicTacToeGameMap.hpp"
#include "util/resources/Resources.hpp"

class TicTacToeGame {
public:
	TicTacToeGame(sf::RenderWindow& window, Resources* res);
	void run();
private:
	sf::RenderWindow& renderWindow;
	Resources* resources;

	bool isPlaying;

	sf::Text headerLabel;

	void mainLoop();
	void onExit();
};
