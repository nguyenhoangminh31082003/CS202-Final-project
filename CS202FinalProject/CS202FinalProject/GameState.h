#pragma once

#include "State.h"
#include "RoadCrossingGame.h"

class GameState : public State {
private:

	RoadCrossingGame roadCrossingGame;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	void initializeBacktround();

public:

	GameState(sf::RenderWindow * const window, std::stack<State*> * const states);

	virtual ~GameState();

	void updateEvents();
	void update();

	void render();
	void render(sf::RenderWindow * const target);

};