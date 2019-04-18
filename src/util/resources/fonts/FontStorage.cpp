#include "FontStorage.hpp"

FontStorage::FontStorage() {
	robotoLight.reset(new sf::Font());
	robotoRegular.reset(new sf::Font());
	robotoThin.reset(new sf::Font());
}

sf::Font& FontStorage::GetRobotoLight() {
	return *robotoLight;
}

sf::Font& FontStorage::GetRobotoRegular() {
	return *robotoRegular;
}

sf::Font& FontStorage::GetRobotoThin() {
	return *robotoThin;
}

void FontStorage::LoadFonts() {
	if (!robotoRegular->loadFromFile("Roboto-Regular.ttf")) {
		exit(0x1);
	}
	if (!robotoLight->loadFromFile("Roboto-Light.ttf")) {
		exit(0x1);
	}
	if (!robotoThin->loadFromFile("Roboto-Thin.ttf")) {
		exit(0x1);
	}
}

void FontStorage::SetSmoothing(bool val) {
	for(int i = 1; i < 128; i++)
		const_cast<sf::Texture&>(robotoRegular->getTexture(i)).setSmooth(val);
	for (int i = 1; i < 128; i++)
		const_cast<sf::Texture&>(robotoLight->getTexture(i)).setSmooth(val);
	for (int i = 1; i < 128; i++)
		const_cast<sf::Texture&>(robotoThin->getTexture(i)).setSmooth(val);
}
