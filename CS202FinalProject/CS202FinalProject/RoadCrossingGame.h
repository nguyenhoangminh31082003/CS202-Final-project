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

enum GAME_STATUS {
	CURRENT_PLAYED = 0,
	PAUSED = 1,
	LOSE = 2,
	WIN = 3
};

class RoadCrossingGame {
private:

	Timer timer;	
	TimerDisplay timerDisplay;

	std::vector<Road*> roads;
	Player player;

	sf::Sprite statusImage;

	int rowID, columnID, levelID;
	GAME_STATUS status;

	void setPositionsOfRoads();
	bool updateLevel(const int newLevelID);

	void initializePlayer();
	void initializeLevel();
	void initializeTimer();

	void clearRoads();

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
	GAME_STATUS getGameStatus() const;
	void pauseGame();
	void continueGame();
	void resetCurrentLevel();

};