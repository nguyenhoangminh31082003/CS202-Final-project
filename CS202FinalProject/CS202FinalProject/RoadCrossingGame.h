#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include "SimpleRoad.h"
#include "Player.h"

class RoadCrossingGame {
private:

	/*
	
	Timer timer;
	
	*/

	std::vector<SimpleRoad> roads;
	Player player;

	sf::Sprite statusImage;

	int roadID, levelID, status;

	void setPositionsOfRoads();
	bool updateLevel(const int newLevelID);

public:

	RoadCrossingGame();

	~RoadCrossingGame();

	void render(sf::RenderTarget* const window);
	void update();
	bool saveGameToTextFile();

	/*
	bool loadGameFromFile();
	void pauseGame();
	void resetGame();
	void resetCurrentLevel();
	void continueGame();
	void updateStatus();
	*/

};