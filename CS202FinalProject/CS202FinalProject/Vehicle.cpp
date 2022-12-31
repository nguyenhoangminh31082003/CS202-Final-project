#include "Vehicle.h"

Vehicle::Vehicle(): Obstacle() {};

Vehicle::Vehicle(const std::vector<sf::Texture>& carModels): Obstacle(carModels) {};

Vehicle::Vehicle(const double dx, const double dy, const std::vector<sf::Texture>& carModels) : Obstacle(dx, dy, carModels){};

Vehicle::Vehicle(std::ifstream& inputFile, const std::vector<sf::Texture>& carModels): Obstacle(inputFile, carModels) {};

Vehicle::~Vehicle() {};