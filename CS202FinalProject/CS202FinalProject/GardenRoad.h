#pragma once


#include "Road.h"

class GardenRoad : public Road {
private:

	const static int MAXIMUM_NUMBER_OF_OBSTACLES = 7;

	std::vector<Obstacle*> obstacles;

	bool checkValid() const;
	void clearAllObstacles();

public:

	GardenRoad();
	GardenRoad(const int numberOfObstacles);

	~GardenRoad();

	void update(float dTime);
	void movePositionVertically(const double dy);
	void render(sf::RenderTarget* const target);
	bool checkCollision(const Player& player);
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

	std::string getRoadType() const;

	void startSound();
	void endSound();

};