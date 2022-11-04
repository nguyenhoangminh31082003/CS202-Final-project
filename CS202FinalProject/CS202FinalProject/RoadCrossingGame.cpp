#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

RoadCrossingGame::~RoadCrossingGame() {
	/*
	
		Note:
			(this -> window) should not be deleted here.
	
	*/
};

bool RoadCrossingGame::updateLevel(const int newLevelID) {
	//(this->levelID) = newLevelID;
	const std::string path = "Data/Levels/level_" + Helper::convertIntToString(newLevelID);
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		int numberOfRoads, numberOfObstacles;
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		for (int i = 0; i < numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
		}
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}