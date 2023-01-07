#pragma once

#include "State.h"
#include "RoadCrossingGame.h"
#include "Button.h"

class GameState : public State {
private:

	bool loadGame;
	InputTextBox inputTextBox;

	RoadCrossingGame roadCrossingGame;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Music music;
	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();

	void renderButtons(sf::RenderTarget * const target);

	void deleteAllButtons();

	void initializeInputTextBox();

public:

	GameState(sf::RenderWindow * const window, std::vector<State*> * const states, GameOptions* gameOptions);
	GameState(sf::RenderWindow * const window, std::vector<State*> * const states, const std::string &requests, GameOptions* gameOptions);

	virtual ~GameState();

	void updateEvents();
	void update();

	void render();
	void render(sf::RenderWindow * const target);

};