#pragma once

#include "State.h"

class ScoreboardState : public State {
private:
public:
	ScoreboardState(sf::RenderWindow* window, std::stack<State*>* states);


	void updateEvents();

	void update();

	void render(sf::RenderWindow* const target);
};