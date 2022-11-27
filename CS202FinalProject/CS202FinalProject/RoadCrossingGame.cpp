#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

void RoadCrossingGame::setPositionsOfRoads() {
	sf::Vector2f position(300, 0);
	for (Road &road : (this->roads)) {
		road.setRoadPosition(position);
		std::cerr << "Position of road is set to " << position.x << ' ' << position.y << '\n';
		position.x += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(): player("Data/Images/player.png") {
	(this -> levelID) = 0;
	this->updateLevel(this -> levelID);

	//(this -> player) = Player("Data/Images/player.png");
	(this -> player).setPosition(200, 400);
	(this -> player).setSpeed(100);
};

RoadCrossingGame::~RoadCrossingGame() {};

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
		this -> setPositionsOfRoads();
		for (int i = 1; i <= numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
			if (numberOfObstacles > 0) {
				inputFile >> speed;
				(this->roads)[i].appendObstaclesWithSpeed(speed, numberOfObstacles);
			}
		}
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}

void RoadCrossingGame::render(sf::RenderTarget * const window) {
	for (Road& road : (this -> roads))
		road.render(window);
	(this->player).render(window);
};

void RoadCrossingGame::update() {
	for (Road& road : (this->roads))
		road.update();
};

bool RoadCrossingGame::saveGameToTextFile() {
	const std::string path = "Data/SaveGame/saveGame.txt";
	std::ofstream outputFile(path.c_str());
	const bool result = outputFile.is_open();
	if (result) {
		outputFile << (this -> levelID) << '\n';
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	outputFile.close();
	return result;
};

bool RoadCrossingGame::saveGameToTextFile(const std::string &path) {
	std::ofstream outputFile(path.c_str());
	const bool result = outputFile.is_open();
	if (result) {
		outputFile << (this->levelID) << '\n';
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	outputFile.close();
	return result;
};

void RoadCrossingGame::updateWithEvent(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Up:
			std::cerr << "Player moves up" << '\n';
			//(this->player).moveUp();
			(this->player).moveUp(0, 1000);
			break;
		case sf::Keyboard::Down:
			std::cerr << "Player moves down" << '\n';
			//(this->player).moveDown();
			(this->player).moveDown(0, 1000);
			break;
		case sf::Keyboard::Left:
			std::cerr << "Player moves left" << '\n';
			//(this->player).moveLeft();
			(this->player).moveLeft(0, 1500);
			break;
		case sf::Keyboard::Right:
			std::cerr << "Player moves right" << '\n';
			//(this->player).moveRight();
			(this->player).moveRight(0, 1500);
			break;
		}
		break;
	}
};


bool RoadCrossingGame::loadGameFromFile() {
	return true;
};

bool RoadCrossingGame::loadGameFromFile(const std::string& path) {
	return true;
};