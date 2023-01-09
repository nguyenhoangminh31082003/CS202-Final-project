#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <iostream>

#include "Obstacle.h"

class Vehicle : public Obstacle {
public:

	Vehicle();
	Vehicle(const std::vector<sf::Texture>& carModels);
	Vehicle(std::ifstream& inputFile, const std::vector<sf::Texture>& carModels);
	Vehicle(const double dx, const double dy, const std::vector<sf::Texture>& carModels);

	~Vehicle();

};