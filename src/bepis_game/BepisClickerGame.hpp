#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "util/resources/Resources.hpp"

class BepisClickerGame {
public:
	BepisClickerGame(sf::RenderWindow& window, Resources* res);
	void run();
private:
	sf::RenderWindow& renderWindow;
	Resources* resources;

	sf::RectangleShape clickButton;
	sf::Text clickButtonLabel;

	sf::Text clicksLabel;
	sf::Text clicksCounterLabel;

	bool isPlaying;
	int clicks;

	void mainLoop();
	void onExit();
};
