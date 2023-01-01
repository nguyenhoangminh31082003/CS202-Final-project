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
	Obstacle(const std::vector<sf::Texture> &models);
	Obstacle(std::ifstream& inputFile , const std::vector<sf::Texture>& models);
	Obstacle(const double dx, const double dy, const std::vector<sf::Texture> & models);

	virtual ~Obstacle();

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
	virtual sf::FloatRect getBounds() const;

	virtual bool checkCollision(const Obstacle &obstacle) const;
	
	double getHeight() const;
	virtual double getWidth() const;

	
	/*
	double getWidthOfImage() const;
	sf::FloatRect getBoundsOfImage() const;
	*/

	double getSpeedX() const;
	double getSpeedY() const;

	virtual void saveToTextFile(std::ofstream &outputFile) const;
	virtual void readFromTextFile(std::ifstream &inputFile);

	sf::Vector2f getSouthWestCornerPosition() const;

	friend std::ostream& operator << (std::ostream &outputStream, const Obstacle &obstacle);
};