#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "fonts/FontStorage.hpp"

class Resources {
public:
	Resources();
	FontStorage& GetFontStorage();
	void LoadResources();
private:
	std::unique_ptr<FontStorage> fontStorage;
};
