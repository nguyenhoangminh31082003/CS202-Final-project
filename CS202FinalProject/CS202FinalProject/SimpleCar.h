#pragma once

#include "Box.h"

class SimpleCar {
private:

	sf::RectangleShape carImage;
	double dx, dy;

public:

	SimpleCar();

	void render(sf::RenderTarget * const window);
	void setPosition(const double x, const double y);
	void setVelocity(const double dx, const double dy);
	void movePosition();

};