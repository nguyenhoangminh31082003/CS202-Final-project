#pragma once
#include "Button.h"
#include "State.h"
#include "GameState.h"

class PlayMenuState : public State
{
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();
public:
	PlayMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	PlayMenuState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~PlayMenuState();

	void updateEvents();
	void updateButtons();
	void update();
	//void renderButtons(sf::RenderTarget * target);
	void render(sf::RenderWindow* target);
};