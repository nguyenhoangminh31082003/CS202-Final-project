#pragma once

#include <vector>

#include "RailRoadCar.h"

class Train : public Obstacle {
private:
public:

	Train();
	Train(const double dx, const double dy);

	~Train();

};