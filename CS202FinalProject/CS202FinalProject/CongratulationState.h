#pragma once

#include "State.h"
#include "Button.h"
#include "InputTextBox.h"
#include "RoadCrossingGame.h"

class CongratulationState : public State {
private:
	
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::Text message;
	sf::Font font;
	InputTextBox nameBox;
	std::map<std::string, Button*> buttons;
	RoadCrossingGame const& roadCrossingGame;

	void initializeBackground();
	void initializeMessage();
	void initializeNameBox();
	void initializeButtons();
	void initializeFont();

public:

	CongratulationState(sf::RenderWindow* window, std::stack<State*>* states, RoadCrossingGame const &roadCrossingGame);

	virtual ~CongratulationState();

	void updateEvents();
	void update();
	void render(sf::RenderWindow* const target);

};