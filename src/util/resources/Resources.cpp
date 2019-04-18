#include "Resources.hpp"

Resources::Resources() {
	fontStorage.reset(new FontStorage());
}

void Resources::LoadResources() {
	fontStorage->LoadFonts();
}

FontStorage& Resources::GetFontStorage() {
	return *fontStorage;
}
