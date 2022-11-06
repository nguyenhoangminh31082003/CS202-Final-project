#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include "SimpleRoad.h"

class RoadCrossingGame {
private:

	sf::RenderWindow* window;

	/*
	
	Timer timer;
	
	*/

	std::vector<SimpleRoad> roads;

	sf::Sprite statusImage;

	int roadID, levelID, status;

	void setPositionsOfRoads();
	bool updateLevel(const int newLevelID);

public:

	RoadCrossingGame(sf::RenderWindow * const renderWindow);

	~RoadCrossingGame();

	void render();

	/*
	void update();
	bool saveGameToFile();
	bool loadGameFromFile();
	void pauseGame();
	void resetGame();
	void resetCurrentLevel();
	void continueGame();
	void updateStatus();
	*/

};