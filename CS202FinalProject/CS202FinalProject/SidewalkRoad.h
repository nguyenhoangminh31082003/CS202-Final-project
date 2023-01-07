#pragma once

#include "Road.h"

class SidewalkRoad : public Road {
private:
public:

	SidewalkRoad();
	~SidewalkRoad();

	bool checkCollision(const Player& player) const;
	void update(float dTime);

	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

	friend std::ostream& operator << (std::ostream &outputStream, const SidewalkRoad &sidewalkRoad);

};