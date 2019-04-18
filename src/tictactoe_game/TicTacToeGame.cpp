#include "TicTacToeGame.hpp"
#include "util/element/ElementUtil.hpp"

TicTacToeGame::TicTacToeGame(sf::RenderWindow& window, Resources* res) : renderWindow(window), resources(res) {
	isPlaying = true;
	{
		sf::Text _headerLabel((const std::string)"Not implemented! Press ESC", resources->GetFontStorage().GetRobotoRegular(), 32);
		_headerLabel.setPosition(0, 200.f);
		ElementUtil::centerTextHorizontal(&_headerLabel);
		headerLabel = _headerLabel;
	}
}

void TicTacToeGame::run() {
	mainLoop();
	onExit();
}

void TicTacToeGame::mainLoop() {
	while (isPlaying) {
		sf::Event event;
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				renderWindow.close();
				exit(0x0);
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
				isPlaying = false;
				break;
			}
		}
		renderWindow.clear(sf::Color::Black);
		renderWindow.draw(headerLabel);
		renderWindow.display();
	}
}

void TicTacToeGame::onExit() {

}
