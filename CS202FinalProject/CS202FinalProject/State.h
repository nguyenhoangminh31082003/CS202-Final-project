#pragma once
#include <ctime>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <stack>
#include "MainProgram.h"
//#include "Entity.h"
#include "GameOptions.h"

class State
{
private:


protected:
	std::stack<State*>* states;
	GameOptions* gameOptions;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	std::map<std::string, sf::Texture*> textures;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



	virtual void initKeyBinds() = 0;
public:

	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~State();
	sf::Event ev;

	const bool& getQuit() const;
	void endState();
	virtual void updateMousePos();
	virtual void updateInput(const float& dt) = 0;

	virtual void updateEvents() = 0;
	//pure virtual classes


	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

