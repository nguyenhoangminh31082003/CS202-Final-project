#pragma once
#include "Button.h"
#include "State.h"

class MainMenuState : public State
{
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~MainMenuState();

	void updateEvents();
	void updateButtons();
	void update();
	//void renderButtons(sf::RenderTarget * target);
	void render(sf::RenderWindow* target);
};