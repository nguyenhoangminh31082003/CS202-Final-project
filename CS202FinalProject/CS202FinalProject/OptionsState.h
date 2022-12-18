#pragma once
#include "Button.h"
#include "State.h"

class OptionsState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();
public:
	OptionsState(sf::RenderWindow* window, std::stack<State*>* states);
	OptionsState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~OptionsState();

	void updateEvents();
	void updateButtons();
	void update();
	//void renderButtons(sf::RenderTarget * target);
	void render(sf::RenderWindow* const target);
};