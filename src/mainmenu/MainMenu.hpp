#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../util/resources/Resources.hpp"

class MainMenu {
public:
	MainMenu(sf::RenderWindow& window, Resources* res);
	void run();
private:
	bool isPlaying;
	sf::RenderWindow& renderWindow;
	Resources* resources;

	sf::Text headerLabel;
	sf::Text bepisLauncherButtonLabel;
	sf::Text tictactoeLauncherButtonLabel;
	sf::Text exitButtonLabel;

	sf::RectangleShape bepisLauncherButton;
	sf::RectangleShape tictactoeLauncherButton;
	sf::RectangleShape exitButton;

	void mainLoop();
	void onExit();
};
