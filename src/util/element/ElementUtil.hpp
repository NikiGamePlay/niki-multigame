#pragma once
#include "SFML/Graphics.hpp"

class ElementUtil {
public:
	static void centerShapeHorizontal(sf::Shape* element);
	static void centerTextHorizontal(sf::Text* text);
	static void centerShapeInsideShapeHorizontal(sf::Shape* text, sf::Shape* rectangle);
	static void centerTextInsideShapeHorizontal(sf::Text* text, sf::Shape* shape);
};
