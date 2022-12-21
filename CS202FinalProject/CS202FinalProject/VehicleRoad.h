#pragma once

#include "Road.h"

class VehicleRoad : public Road {
private:

	const static int MAXIMUM_NUMBER_OF_OBSTACLES = 4;

	std::vector<Obstacle*> obstacles;

	bool checkValid() const;
	void clearAllObstacles();

public:

	VehicleRoad();
	~VehicleRoad();

	void update();
	void render(sf::RenderTarget* const window);
	bool appendObstaclesWithSpeed(const double speed, const int numberOfObstacles, std::vector<sf::Texture> carModels);
	bool checkCollision(const Player& player) const;
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};