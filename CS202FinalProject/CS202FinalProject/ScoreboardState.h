#pragma once

#include <vector>

#include "State.h"
#include "Button.h"

class ScoreboardState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;
	std::vector<std::pair<int, double> > score;

	void initializeBackground();
	void initializeButtons();
	void loadScore();
	void saveScore();
public:
	ScoreboardState(sf::RenderWindow* window, std::stack<State*>* states);


	void updateEvents();

	void update();

	void render(sf::RenderWindow* const target);

	~ScoreboardState();
};