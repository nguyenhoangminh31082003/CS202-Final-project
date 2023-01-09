#pragma once

#include "Road.h"
#include "Train.h"

enum RAILWAY_ROAD_STATUS {
	TRAIN_IS_RUNNING = 0,
	TRAIN_IS_COMING = 1,
	NO_TRAIN = 2
};

class RailwayRoad : public Road {
private:

	Train train;
	int remainingTime;

	RAILWAY_ROAD_STATUS status;

	void resetTrainPosition();

public:

	RailwayRoad();

	~RailwayRoad();

	void update(float dTime);
	void movePositionVertically(const double dy);
	void render(sf::RenderTarget* const target);
	bool checkCollision(const Player& player);
	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

	void startSound();
	void endSound();

	std::string getRoadType() const;

	friend std::ostream& operator << (std::ostream &outputStream, const RailwayRoad &railwayRoad);

};