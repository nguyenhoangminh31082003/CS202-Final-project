#include "Cactus.h"

Cactus::Cactus() : Obstacle() {
	(this->texture).loadFromFile("Data/Images/Roads/DesertRoads/cactus.jpg");
	(this->model).setTexture(this -> texture);
};

Cactus::~Cactus() {};