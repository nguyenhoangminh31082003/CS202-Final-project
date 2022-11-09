#pragma once

#include "Box.h"

class SimpleCar {
private:

	sf::RectangleShape carImage;
	double dx, dy;

public:

	SimpleCar();

	void render(sf::RenderTarget * const window) const;
	void setPosition(const double x, const double y);
	void setVelocity(const double dx, const double dy);
	void movePosition();

	double getYofNorthBound() const;
	double getYofSouthBound() const;
	double getHeight() const;
	double getWidth() const;

};