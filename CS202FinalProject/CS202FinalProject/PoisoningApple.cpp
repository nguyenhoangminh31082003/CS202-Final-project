#include "PoisoningApple.h"

PoisoningApple::PoisoningApple() : Obstacle() {
	(this->texture).loadFromFile("Data/Images/Roads/GardenRoads/apple.png");
	(this->model).setTexture(this->texture);
};

PoisoningApple::~PoisoningApple() {};