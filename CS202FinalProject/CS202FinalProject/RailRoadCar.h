#pragma once

#include "Obstacle.h"

class RailRoadCar : public Obstacle {
private:
public:

	RailRoadCar();
	RailRoadCar(const double dx, const double dy, const bool head);

	~RailRoadCar();

};