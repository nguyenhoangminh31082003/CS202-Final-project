#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <iostream>

#include "Obstacle.h"

class Vehicle : public Obstacle {
protected:

	sf::RectangleShape image;
	sf::Texture texture;
	sf::Sprite model;
	double dx, dy;

public:

	Vehicle();
	Vehicle(const std::vector<sf::Texture>& carModels);
	Vehicle(std::ifstream& inputFile, const std::vector<sf::Texture>& carModels);
	Vehicle(const double dx, const double dy, const std::vector<sf::Texture>& carModels);

	~Vehicle();

};