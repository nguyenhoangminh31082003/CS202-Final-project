#pragma once

#include "Road.h"
#include "Train.h"

class RailwayRoad : public Road {
private:

	Train train;

	/*
	bool checkValid() const;
	void clearAllObstacles();
	*/
public:

	RailwayRoad();

	~RailwayRoad();

	void update(float dTime);
	void movePositionVertically(const double dy);
	void render(sf::RenderTarget* const target);
	bool checkCollision(const Player& player) const;
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};