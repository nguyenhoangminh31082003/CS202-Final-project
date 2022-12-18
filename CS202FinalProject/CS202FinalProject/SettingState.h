#pragma once

#include "State.h"

class SettingState : public State {
private:
public:
	SettingState(sf::RenderWindow* window, std::stack<State*>* states);

	void updateEvents();

	void update();

	void render(sf::RenderWindow* const target);
};