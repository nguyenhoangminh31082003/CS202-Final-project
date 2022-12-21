#pragma once

#include "Road.h"

class GrassRoad : public Road {
private:
public:

	GrassRoad();
	~GrassRoad();

	bool checkCollision(const Player& player) const;
	void update();

	void saveToTextFile(std::ofstream& outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

};