#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "mainmenu/MainMenu.hpp"
#include "util/resources/Resources.hpp"
#include "util/Defines.hpp"

int main()
{
	std::cout << "Awesome2D 0.13 alpha" << std::endl;
	std::cout << "Welcome to Niki's Multigame version 0.12" << std::endl;
	{
		std::unique_ptr<sf::RenderWindow> windowPtr(new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Niki's Multigame", sf::Style::Titlebar | sf::Style::Close));
		windowPtr->setVerticalSyncEnabled(false);

		std::unique_ptr<Resources> resourcesPtr(new Resources());
		resourcesPtr->LoadResources();

		std::unique_ptr<MainMenu> mainMenuPtr(new MainMenu(*windowPtr, resourcesPtr.get()));
		mainMenuPtr->run();
	}
	std::cout << "Awesome2D - Goodbye!" << std::endl;
	return 0;
}
