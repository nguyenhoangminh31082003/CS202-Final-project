#pragma once

#include "State.h"
#include "Button.h"

class ScoreboardState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();
public:
	ScoreboardState(sf::RenderWindow* window, std::stack<State*>* states);


	void updateEvents();

	void update();

	void render(sf::RenderWindow* const target);

	~ScoreboardState();
};