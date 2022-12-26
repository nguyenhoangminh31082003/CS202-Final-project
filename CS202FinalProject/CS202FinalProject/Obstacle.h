#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <iostream>

#include "Box.h"

class Obstacle {
protected:

	sf::RectangleShape image;
	sf::Texture texture;
	sf::Sprite model;
	double dx, dy;

public:

	Obstacle();
	Obstacle(const std::vector<sf::Texture> &carModels);
	Obstacle(const double dx, const double dy, std::vector<sf::Texture> carModels);

	sf::Vector2f getPosition() const;

	virtual void render(sf::RenderTarget * const window) const;
	void setPosition(const double x, const double y);
	void setVelocity(const double dx, const double dy);
	void movePosition();
	virtual void movePosition_wAnim(float dTime) {};
	void movePositionVertically(const double dy);

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

	friend std::ostream& operator << (std::ostream &outputStream, const Obstacle &obstacle);
};