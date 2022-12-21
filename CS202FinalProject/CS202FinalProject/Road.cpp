#include <iostream>
#include <vector>

#include "Road.h"
#include "Helper.h"

Road::Road() {
	/*
	(this -> roadImage).setSize(sf::Vector2f(1500, 100));
	(this -> roadImage).setFillColor(sf::Color(159, 159, 159));
	*/
};

/*
Road::Road(const sf::Vector2f& position) {
	(this->roadImage).setSize(sf::Vector2f(1500, 100));
	(this->roadImage).setPosition(position);

	const int color = ((int)position.y) % 255;

	(this->roadImage).setFillColor(sf::Color(color, color, color));

};
*/

Road::~Road() {
}

void Road::render(sf::RenderTarget* const window) {
	window->draw(this->roadImage);
};

void Road::setRoadPosition(const sf::Vector2f& position) {
	(this->roadImage).setPosition(position);
};

std::ostream& operator << (std::ostream& outputStream, const Road& road) {
	const auto position = (road.roadImage).getPosition();
	const auto size = (road.texture).getSize();
	outputStream << "Road information\n";
	outputStream << "Top left corner: (" << position.x << ", " << position.y << ")\n";
	outputStream << "Size: (" << size.x << ", " << size.y << ")\n";
	return outputStream;
};

void Road::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "NormalRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n';
};

void Road::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> position.x >> position.y;
	this->setRoadPosition(position);
};