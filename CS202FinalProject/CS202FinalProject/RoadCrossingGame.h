#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

#include "Road.h"
#include "Player.h"
#include "Timer.h"
#include "TimerDisplay.h"

class RoadCrossingGame {
private:

	Timer timer;	
	TimerDisplay timerDisplay;

	std::vector<Road> roads;
	Player player;

	sf::Sprite statusImage;

	int rowID, columnID, levelID, status;

	void setPositionsOfRoads();
	bool updateLevel(const int newLevelID);

	void initializePlayer();
	void initializeLevel();
	void initializeTimer();

public:

	RoadCrossingGame();

	~RoadCrossingGame();

	void render(sf::RenderTarget * const window);
	void update();
	void updateWithEvent(const sf::Event &event);
	bool saveGameToTextFile();
	bool saveGameToTextFile(const std::string &path);
	bool readGameFromTextFile();
	bool readGameFromTextFile(const std::string &path);

	/*
	
	void pauseGame();
	void resetGame();
	void resetCurrentLevel();
	void continueGame();
	void updateStatus();
	*/

};