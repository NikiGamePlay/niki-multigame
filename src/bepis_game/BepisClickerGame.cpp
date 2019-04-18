#include "BepisClickerGame.hpp"
#include "util/Defines.hpp"
#include "util/element/ElementUtil.hpp"

BepisClickerGame::BepisClickerGame(sf::RenderWindow& window, Resources* res) : renderWindow(window), resources(res) {
	clicks = 0;
	isPlaying = true;

	sf::Vector2f buttonSize(200, 75);
	{
		sf::Text _clicksLabel((const std::string)"Amount of bepis cans that you own:", resources->GetFontStorage().GetRobotoLight(), 32);

		_clicksLabel.setFillColor(sf::Color::White);
		_clicksLabel.setPosition(0, 100);

		ElementUtil::centerTextHorizontal(&_clicksLabel);

		clicksLabel = _clicksLabel;
	}

	{
		sf::Text _clicksCounterLabel((const std::string)std::to_string(clicks), resources->GetFontStorage().GetRobotoRegular(), 48);

		_clicksCounterLabel.setFillColor(sf::Color::White);
		_clicksCounterLabel.setPosition(0, 150);

		ElementUtil::centerTextHorizontal(&_clicksCounterLabel);

		clicksCounterLabel = _clicksCounterLabel;
	}

	{
		sf::RectangleShape _clickButton;

		_clickButton.setSize(buttonSize);
		_clickButton.setFillColor(sf::Color::Magenta);
		_clickButton.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

		ElementUtil::centerShapeHorizontal(&_clickButton);

		clickButton = _clickButton;
	}

	{
		sf::Text _clickButtonLabel((const std::string)"GIVE MORE!", resources->GetFontStorage().GetRobotoRegular(), 32);

		_clickButtonLabel.setFillColor(sf::Color::White);

		ElementUtil::centerTextInsideShapeHorizontal(&_clickButtonLabel, &clickButton);

		clickButtonLabel = _clickButtonLabel;
	}
}

void BepisClickerGame::run() {
	mainLoop();
	onExit();
}

void BepisClickerGame::mainLoop() {
	while (isPlaying) {
		sf::Event event;
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				renderWindow.close();
				exit(0x0);
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
				isPlaying = false;
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(renderWindow);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (clickButton.getGlobalBounds().contains(mousePosF)) {
					clicks++;
					clicksCounterLabel.setString(std::to_string(clicks));
					ElementUtil::centerTextHorizontal(&clicksCounterLabel);
				}
			}
		}
		renderWindow.clear(sf::Color::Blue);
		renderWindow.draw(clicksLabel);
		renderWindow.draw(clicksCounterLabel);
		renderWindow.draw(clickButton);
		renderWindow.draw(clickButtonLabel);
		renderWindow.display();
	}
}

void BepisClickerGame::onExit() {
	clicks = 0;
	isPlaying = false;
}
