#include "RailRoadCar.h"

RailRoadCar::RailRoadCar(): Obstacle() {};

RailRoadCar::RailRoadCar(const double vx, const double vy, const bool head) {
	this->dx = vx;
	this->dy = vy;
	if (head)
		(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train_head.png");
	else
		(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/rail_road_car.png");
	(this->image).setTexture(&(this -> texture));
};

RailRoadCar::~RailRoadCar() {};
