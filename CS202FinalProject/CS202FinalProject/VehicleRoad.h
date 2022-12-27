#pragma once

#include "Road.h"
#include "TrafficLight.h"

class VehicleRoad : public Road {
private:

	const static int MAXIMUM_NUMBER_OF_OBSTACLES = 4;

	TrafficLight trafficLight;
	std::vector<Obstacle*> obstacles;
	const std::vector<sf::Texture> * carModels;

	bool checkValid() const;
	void clearAllObstacles();

public:

	VehicleRoad(const std::vector<sf::Texture>& carModels);
	VehicleRoad(const int numberOfObstacles, const double speed, const std::vector<sf::Texture> &carModels);

	~VehicleRoad();

	void update(float dTime);
	void movePositionVertically(const double dy);
	void render(sf::RenderTarget* const window);
	bool checkCollision(const Player& player) const;
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};