#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "Helper.h"
#include "RoadCrossingGame.h"

class Generator
{
public:
	static bool generateLevelTxt(std::string location, int firstLevelNumRoads, int numLevels, int init_minSpeed, int init_maxSpeed, int speedScale);
};

