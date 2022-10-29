#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

class RoadCrossingGame {
private:

	sf::RenderWindow* window;

	/*
	
	Timer timer;
	vector<Road> roads;
	
	*/

	sf::Sprite statusImage;

	int roadID, levelID, status;

	/*
	void updateLevel(const int newLevelID);
	*/

public:

	~RoadCrossingGame();

	/*
	void render();
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