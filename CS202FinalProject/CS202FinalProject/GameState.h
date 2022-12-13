#pragma once

#include "State.h"
#include "RoadCrossingGame.h"
#include "Button.h"

class GameState : public State {
private:

	RoadCrossingGame roadCrossingGame;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBacktround();
	void initializeButtons();

	void renderButtons(sf::RenderTarget * const target);
	void updateButtons();

public:

	GameState(sf::RenderWindow * const window, std::stack<State*> * const states);

	virtual ~GameState();

	void updateEvents();
	void update();

	void render();
	void render(sf::RenderWindow * const target);

};