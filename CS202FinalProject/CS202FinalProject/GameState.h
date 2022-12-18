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

	void deleteAllButtons();

public:

	GameState(sf::RenderWindow * const window, std::stack<State*> * const states);
	GameState(sf::RenderWindow* const window, std::stack<State*>* const states, const bool savedOldGame);

	virtual ~GameState();

	void updateEvents();
	void update();

	void render();
	void render(sf::RenderWindow * const target);

};