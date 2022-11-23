#pragma once
#include <ctime>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//#include "Entity.h"
#include "GameOptions.h"

class State
{
private:


protected:
	std::stack<State*>* states;
	GameOptions* gameOptions;
	sf::RenderWindow* window;
	std::map<std::string, sf::Texture*> textures;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



public:

	State(sf::RenderWindow* window, std::stack<State*>* states);
	State(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~State();
	sf::Event ev;

	const bool& getQuit() const;
	void endState();
	virtual void updateMousePos();

	virtual void updateEvents() = 0;
	//pure virtual classes


	virtual void update() = 0;
	virtual void render(sf::RenderWindow* target = nullptr) = 0;
};

