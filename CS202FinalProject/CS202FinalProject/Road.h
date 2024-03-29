#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <vector>

#include "Player.h"
#include "Obstacle.h"

class Road {
protected:

	sf::Texture texture;
	sf::Sprite roadImage;

public:

	Road();
	
	//Road(const sf::Vector2f &position);
	
	virtual ~Road();

	virtual void movePositionVertically(const double dy);
	virtual void setRoadPosition(const sf::Vector2f &position);
	virtual void render(sf::RenderTarget * const window);
	virtual bool checkCollision(const Player& player) = 0;
	virtual void update(float dTime) = 0;
	virtual void saveToTextFile(std::ofstream& outputFile) const;
	virtual void readFromTextFile(std::ifstream& inputFile);
	virtual void startSound() = 0;
	virtual void endSound() = 0;

	virtual std::string getRoadType() const;

	friend std::ostream& operator << (std::ostream &outputStream, const Road &road);

};