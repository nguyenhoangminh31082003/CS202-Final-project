#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

void RoadCrossingGame::setPositionsOfRoads() {
	sf::Vector2f position(200, 100);
	for (SimpleRoad &road : (this->roads)) {
		road.setRoadPosition(position);
		std::cerr << "Position of road is set to " << position.x << ' ' << position.y << '\n';
		position.x += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(sf::RenderWindow* const renderWindow) {
	(this->window) = renderWindow;
	(this->levelID) = 0;
	this->updateLevel(this -> levelID);
};

RoadCrossingGame::~RoadCrossingGame() {
	/*
	
		Note:
			(this -> window) should not be deleted here.
	
	*/
};

bool RoadCrossingGame::updateLevel(const int newLevelID) {
	//(this->levelID) = newLevelID;
	const std::string path = "Data/Levels/level_" + Helper::convertIntToString(newLevelID) + ".txt";
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		int numberOfRoads, numberOfObstacles;
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		(this -> roads).resize(numberOfRoads);
		for (int i = 0; i < numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
		}
		this->setPositionsOfRoads();
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}

void RoadCrossingGame::render() {
	for (SimpleRoad& road : (this -> roads))
		road.render(window);
};