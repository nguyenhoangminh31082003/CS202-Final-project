#pragma once

#include "State.h"
#include "Button.h"
#include "Timer.h"

class WaitingState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	Timer timer;

	void initializeBackground();

public:

	WaitingState(sf::RenderWindow* window, std::stack<State*>* states);
	
	virtual ~WaitingState();

	void updateEvents();
	void updateButtons();
	void update();
	void render(sf::RenderWindow* const target);

};