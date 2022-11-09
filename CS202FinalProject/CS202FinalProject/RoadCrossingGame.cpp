#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

void RoadCrossingGame::initializeBridges() {
	(this->upperBridge).setSize(sf::Vector2f(1500, 100));
	(this->lowerBridge).setSize(sf::Vector2f(1500, 100));

	(this->upperBridge).setFillColor(sf::Color(213, 104, 50)); /* red */
	(this->lowerBridge).setFillColor(sf::Color(213, 104, 50));

	(this->upperBridge).setPosition(sf::Vector2f(0, 0));
	(this->lowerBridge).setPosition(sf::Vector2f(0, 900));

};

void RoadCrossingGame::setPositionsOfRoads() {
	sf::Vector2f position(300, 100);
	for (SimpleRoad &road : (this->roads)) {
		road.setRoadPosition(position);
		std::cerr << "Position of road is set to " << position.x << ' ' << position.y << '\n';
		position.x += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(sf::RenderWindow* const renderWindow) {
	this->initializeBridges();
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
		double speed;
		int numberOfRoads, numberOfObstacles;
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		(this -> roads).resize(numberOfRoads + 2);
		for (int i = 1; i <= numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
			for (int j = 0; j < numberOfObstacles; ++j) {
				inputFile >> speed;
				(this->roads)[i].appendCarWithSpeed(speed);
			}
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
	window->draw(upperBridge);
	window->draw(lowerBridge);
};

void RoadCrossingGame::update() {
	for (SimpleRoad& road : (this->roads))
		road.update();
};