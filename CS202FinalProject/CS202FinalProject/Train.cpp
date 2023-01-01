#include "Helper.h"

#include "Train.h"

Train::Train() : Obstacle() {
	this->dx = 10;
	this->dy = 0;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
};

Train::Train(const double vx, const double vy) {
	this->dx = vx;
	this->dy = vy;
	(this->texture).loadFromFile("Data/Images/Roads/RailwayRoads/train.png");
	(this->image).setTexture(&(this->texture));
};

Train::~Train() {};
