#include "MainMenu.hpp"
#include "bepis_game/BepisClickerGame.hpp"
#include "tictactoe_game/TicTacToeGame.hpp"
#include "util/element/ElementUtil.hpp"

MainMenu::MainMenu(sf::RenderWindow& window, Resources* res) : renderWindow(window), resources(res) {
	isPlaying = true;

	sf::Vector2f buttonSize(200, 50);
	sf::Color welcomeTextColor = sf::Color::White;
	sf::Color buttonColor = sf::Color::Blue;
	sf::Color buttonTextColor = sf::Color::White;

	{
		sf::Text _headerLabel((const std::string)"Welcome to Niki's Multigame!", resources->GetFontStorage().GetRobotoRegular(), 32);

		_headerLabel.setFillColor(welcomeTextColor);
		_headerLabel.setPosition(0, 100);

		ElementUtil::centerTextHorizontal(&_headerLabel);

		headerLabel = _headerLabel;
	}

	{
		sf::RectangleShape _bepisLauncherButton;

		_bepisLauncherButton.setSize(buttonSize);
		_bepisLauncherButton.setFillColor(buttonColor);
		_bepisLauncherButton.setPosition(300, 200);

		bepisLauncherButton = _bepisLauncherButton;
	}

	{
		sf::RectangleShape _tictactoeLauncherButton;

		_tictactoeLauncherButton.setSize(buttonSize);
		_tictactoeLauncherButton.setFillColor(buttonColor);
		_tictactoeLauncherButton.setPosition(300, 275);

		tictactoeLauncherButton = _tictactoeLauncherButton;
	}

	{
		sf::RectangleShape _exitButton;

		_exitButton.setSize(buttonSize);
		_exitButton.setFillColor(buttonColor);
		_exitButton.setPosition(300, 350);

		exitButton = _exitButton;
	}

	{
		sf::Text _bepisLauncherButtonLabel((const std::string)"Launch Bepis Clicker", resources->GetFontStorage().GetRobotoLight(), 20);

		_bepisLauncherButtonLabel.setFillColor(buttonTextColor);

		ElementUtil::centerTextInsideShapeHorizontal(&_bepisLauncherButtonLabel, &bepisLauncherButton);

		bepisLauncherButtonLabel = _bepisLauncherButtonLabel;
	}

	{
		sf::Text _tictactoeLauncherButtonLabel((const std::string)"Launch TicTacToe", resources->GetFontStorage().GetRobotoLight(), 20);

		_tictactoeLauncherButtonLabel.setFillColor(buttonTextColor);

		ElementUtil::centerTextInsideShapeHorizontal(&_tictactoeLauncherButtonLabel, &tictactoeLauncherButton);

		tictactoeLauncherButtonLabel = _tictactoeLauncherButtonLabel;
	}

	{
		sf::Text _exitButtonLabel((const std::string)"Exit", resources->GetFontStorage().GetRobotoLight(), 20);

		_exitButtonLabel.setFillColor(buttonTextColor);

		ElementUtil::centerTextInsideShapeHorizontal(&_exitButtonLabel, &exitButton);

		exitButtonLabel = _exitButtonLabel;
	}
}

void MainMenu::mainLoop() {
	while (isPlaying) {
		sf::Event event;
		while (renderWindow.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) { // when ESC is pressed on keyboard or when user clicks X on the window
				isPlaying = false;
				break;
			}

			if (event.type == sf::Event::MouseMoved) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(renderWindow);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (bepisLauncherButton.getGlobalBounds().contains(mousePosF)) {
					bepisLauncherButton.setFillColor(sf::Color::Red);
				}
				else {
					bepisLauncherButton.setFillColor(sf::Color::Blue);
				}

				if (tictactoeLauncherButton.getGlobalBounds().contains(mousePosF)) {
					tictactoeLauncherButton.setFillColor(sf::Color::Red);
				}
				else {
					tictactoeLauncherButton.setFillColor(sf::Color::Blue);
				}

				if (exitButton.getGlobalBounds().contains(mousePosF)) {
					exitButton.setFillColor(sf::Color::Red);
				}
				else {
					exitButton.setFillColor(sf::Color::Blue);
				}
			}

			if (event.type == sf::Event::MouseButtonPressed) { // handles button clicks
				sf::Vector2i mousePos = sf::Mouse::getPosition(renderWindow); // get mouse position
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)); // convert it to float
				if (bepisLauncherButton.getGlobalBounds().contains(mousePosF)) { // check if mouse was on the button
					std::unique_ptr<BepisClickerGame> bepisGamePtr(new BepisClickerGame(renderWindow, resources));
					//BepisClickerGame _bepisGame(renderWindow, resources);
					//_bepisGame.run(); // create instance of BepisClickerGame and run it
					//_bepisGame.~BepisClickerGame();
					bepisGamePtr->run();
				}
				if (tictactoeLauncherButton.getGlobalBounds().contains(mousePosF)) {
					//TicTacToeGame _ticTacToeGame(renderWindow, resources);
					//_ticTacToeGame.run();
					//_ticTacToeGame.~TicTacToeGame();
					std::unique_ptr<TicTacToeGame> tictactoeGamePtr(new TicTacToeGame(renderWindow, resources));
					tictactoeGamePtr->run();
				}
				if (exitButton.getGlobalBounds().contains(mousePosF)) {
					isPlaying = false;
					break;
				}
			}
		}

		renderWindow.clear(sf::Color::Green);
		renderWindow.draw(headerLabel);
		renderWindow.draw(bepisLauncherButton);
		renderWindow.draw(tictactoeLauncherButton);
		renderWindow.draw(exitButton);
		renderWindow.draw(bepisLauncherButtonLabel);
		renderWindow.draw(tictactoeLauncherButtonLabel);
		renderWindow.draw(exitButtonLabel);
		renderWindow.display();
	}
}

void MainMenu::run() {
	renderWindow.setTitle("Main Menu - Niki's Multigame");
	mainLoop();
	onExit();
}

void MainMenu::onExit() {
	renderWindow.clear();
}
