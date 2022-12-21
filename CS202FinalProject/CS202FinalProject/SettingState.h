#pragma once

#include "State.h"
#include "Button.h"
class SettingState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();
public:


	SettingState(sf::RenderWindow* window, std::stack<State*>* states);
	SettingState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions);
	void updateEvents();

	virtual ~SettingState();
	void update();

	void render(sf::RenderWindow* const target);
};