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

class State {
private:

protected:
	std::map<std::string, sf::Texture*> textures;
	std::vector<State*>* states;
	GameOptions* gameOptions;
	sf::RenderWindow* window;
	bool quit;

	sf::Vector2i mousePositionScreen;
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;

public:

	State(sf::RenderWindow* window, std::vector<State*>* states);
	State(sf::RenderWindow* window, std::vector<State*>* states, GameOptions* gameOptions);
	virtual ~State();
	sf::Event event;

	const bool& getQuit() const;
	void endState();
	void endAllStates();
	virtual void updateMousePosition();

	virtual void updateEvents() = 0;
	/*pure virtual class*/

	virtual void update() = 0;
	virtual void render();
	virtual void render(sf::RenderWindow * const target) = 0;

	friend std::ostream& operator << (std::ostream &outputStream, const State &state);
};

