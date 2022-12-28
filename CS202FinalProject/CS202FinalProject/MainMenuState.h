#pragma once

#include "Button.h"
#include "State.h"
#include "PlayMenuState.h"
#include "ScoreboardState.h"
#include "SettingState.h"

class MainMenuState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();

public:

	MainMenuState(sf::RenderWindow* const window, std::vector<State*>* states);
	MainMenuState(sf::RenderWindow* const window, std::vector<State*>* states, GameOptions* gameOptions);

	virtual ~MainMenuState();

	void updateEvents();
	void update();
	void render(sf::RenderWindow * const target);

};