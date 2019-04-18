#include "ElementUtil.hpp"
#include "util/Defines.hpp"
#include <cmath>

void ElementUtil::centerShapeHorizontal(sf::Shape* element) {
	sf::Vector2f currentPosition = element->getPosition();
	sf::Rect<float> bounds = element->getLocalBounds();
	element->setOrigin(bounds.left + bounds.width / 2.0f,
		bounds.top + bounds.height / 2.0f);
	element->setPosition(WINDOW_WIDTH / 2.0f, currentPosition.y);
}

void ElementUtil::centerTextHorizontal(sf::Text * text) {
	sf::Vector2f currentPosition = text->getPosition();
	sf::Rect<float> bounds = text->getLocalBounds();
	text->setOrigin(bounds.left + bounds.width / 2.0f,
		bounds.top + bounds.height / 2.0f);
	text->setPosition(WINDOW_WIDTH / 2.0f, currentPosition.y);
}

void ElementUtil::centerShapeInsideShapeHorizontal(sf::Shape * text, sf::Shape * rectangle) {
	sf::Rect<float> textBounds = text->getLocalBounds();
	sf::Rect<float> rectBounds = rectangle->getGlobalBounds();
	text->setPosition(
		rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
		rectBounds.top + (rectBounds.height / 2) - (textBounds.height / 2)
	);
}

void ElementUtil::centerTextInsideShapeHorizontal(sf::Text * text, sf::Shape * shape) {
	sf::Rect<float> textBounds = text->getLocalBounds();
	sf::Rect<float> rectBounds = shape->getGlobalBounds();
	text->setPosition(
		std::round(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2)), // WORKAROUND: rounding the numbers to avoid weird font behavior
		std::round(rectBounds.top + (rectBounds.height / 2) - (textBounds.height / 2))
	);
}
