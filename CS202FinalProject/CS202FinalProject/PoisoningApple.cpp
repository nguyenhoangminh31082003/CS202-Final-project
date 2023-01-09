#include "PoisoningApple.h"

PoisoningApple::PoisoningApple() : Obstacle() {
	(this->texture).loadFromFile("Data/Images/Roads/GardenRoads/apple.jpg");
	(this->model).setTexture(this->texture);
};

PoisoningApple::~PoisoningApple() {};