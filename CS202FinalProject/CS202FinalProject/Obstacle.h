#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <iostream>

#include "Box.h"

class Obstacle {
private:

	sf::RectangleShape image;
	double dx, dy;

public:

	Obstacle();

	virtual void render(sf::RenderTarget * const window) const;
	void setPosition(const double x, const double y);
	void setVelocity(const double dx, const double dy);
	void movePosition();

	double getYofNorthBound() const;
	double getYofSouthBound() const;
	double getXofWestBound() const;
	double getXofEastBound() const;
	sf::FloatRect getBounds() const;

	bool checkCollision(const Obstacle &obstacle) const;
	
	double getHeight() const;
	double getWidth() const;

	double getSpeedX() const;
	double getSpeedY() const;

	void saveToTextFile(std::ofstream &outputFile) const;
	void readFromTextFile(std::ifstream &inputFile);

};