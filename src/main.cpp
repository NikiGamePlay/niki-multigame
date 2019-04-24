#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "mainmenu/MainMenu.hpp"
#include "util/resources/Resources.hpp"
#include "util/Defines.hpp"

#define AWESOME2D_VER_MAJOR 0
#define AWESOME2D_VER_MINOR 1
#define AWESOME2D_VER_PATCH 14
#define AWESOME2D_VER_STRING "Awesome2D " + std::to_string(AWESOME2D_VER_MAJOR) + "." + std::to_string(AWESOME2D_VER_MINOR) + "." + std::to_string(AWESOME2D_VER_PATCH)

std::string compilerNameAndVersion() {
#if defined(__clang__)
	std::string buf = "Clang ";
	buf.append(__clang_version__);
#elif defined(__GNUC__)
	std::string buf = "GCC " + std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__);
	buf.append(std::to_string(__GNUC__));
	buf.append(".");
	buf.append(std::to_string(__GNUC_MINOR__));
	buf.append(".");
	buf.append(std::to_string(__GNUC_PATCHLEVEL__));
#elif defined(_MSC_VER)
	std::string buf = "MSVC " + std::to_string(_MSC_VER);
#else
	std::string buf = "Unknown compiler";
#endif
	return buf;
}

int main()
{
	std::string __awsmlabel = AWESOME2D_VER_STRING;
	std::cout << __awsmlabel << compilerNameAndVersion() << std::endl;

	std::cout << "Welcome to Niki's Multigame!" << std::endl;
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
