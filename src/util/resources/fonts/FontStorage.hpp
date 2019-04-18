#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class FontStorage {
public:
	FontStorage();
	void LoadFonts();
	sf::Font& GetRobotoRegular();
	sf::Font& GetRobotoLight();
	sf::Font& GetRobotoThin();
	void SetSmoothing(bool val);
private:
	std::unique_ptr<sf::Font> robotoThin;
	std::unique_ptr<sf::Font> robotoRegular;
	std::unique_ptr<sf::Font> robotoLight;
};
