#pragma once

#include "Road.h"

class SidewalkRoad : public Road {
private:
public:

	SidewalkRoad();
	~SidewalkRoad();

	bool checkCollision(const Player& player) const;
	void update();

	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};