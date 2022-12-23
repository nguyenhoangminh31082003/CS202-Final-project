#include "Obstacle.h"
#include "Helper.h"

Obstacle::Obstacle() {
	(this->image).setSize(sf::Vector2f(100, 100));
	(this->image).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	dx = Helper::getRandomInteger(1, 5);
	dy = Helper::getRandomInteger(1, 5);
};

Obstacle::Obstacle(std::vector<sf::Texture> carModels)
{
	(this->image).setSize(sf::Vector2f(100, 100));
	//(this->image).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	this->texture = carModels[Helper::getRandomInteger(0, carModels.size() - 1)];
	this->model.setTexture(texture);

	dx = Helper::getRandomInteger(1, 5);
	dy = Helper::getRandomInteger(1, 5);
};

Obstacle::Obstacle(const double dx, const double dy, std::vector<sf::Texture> carModels):
	dx(dx), dy(dy)
{
	(this->image).setSize(sf::Vector2f(100, 100));
	//(this->image).setFillColor(sf::Color(Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255), Helper::getRandomInteger(0, 255)));
	this->texture = carModels[Helper::getRandomInteger(0, carModels.size() - 1)];
	this->model.setTexture(texture);
	
	if (dx < 0)
		model.setScale(-1.0f, 1.0f);

};

void Obstacle::render(sf::RenderTarget* const window) const {
	window->draw(this -> model);
};

void Obstacle::movePosition() {
	(this->model).move(dx, dy);
};

void Obstacle::movePositionVertically(const double dy) {
	(this->model).move(0, dy);
};

void Obstacle::setPosition(const double x, const double y) {
	(this->model).setPosition(x, y);
};

void Obstacle::setVelocity(const double dx, const double dy) {
	(this->dx) = dx;
	(this->dy) = dy;
};

double Obstacle::getYofNorthBound() const {
	return (this->model).getPosition().y;
};

double Obstacle::getYofSouthBound() const {
	//return (this->image).getPosition().y + (this->image).getSize().y;
	return (this->model).getPosition().y + (this->model).getGlobalBounds().height;
};

double Obstacle::getXofWestBound() const {
	return (this->model).getPosition().x;
};

double Obstacle::getXofEastBound() const {
	return (this->model).getPosition().x + (this->model).getGlobalBounds().width;
};

double Obstacle::getHeight() const {
	return (this->model).getGlobalBounds().height;
};

double Obstacle::getWidth() const {
	return (this->model).getGlobalBounds().width;
};


sf::FloatRect Obstacle::getBounds() const {
	return (this->model).getGlobalBounds();
};

bool Obstacle::checkCollision(const Obstacle& obstacle) const {
	return (this->model).getGlobalBounds().intersects((obstacle.model).getGlobalBounds());
};

double Obstacle::getSpeedX() const {
	return this->dx;
}; 

double Obstacle::getSpeedY() const {
	return this->dy;
};

void Obstacle::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << (this -> image).getPosition().x << ' ' << (this->image).getPosition().x << ' ' << (this->dx) << ' ' << (this->dy) << '\n';
};

void Obstacle::readFromTextFile(std::ifstream& inputFile) {
	double x, y;
	inputFile >> x >> y >> (this->dx) >> (this->dy);
	(this->image).setPosition(x, y);
};

std::ostream& operator << (std::ostream& outputStream, const Obstacle& obstacle) {
	const auto position = (obstacle.image).getPosition();
	const auto size = (obstacle.image).getSize();
	outputStream << "Obstacle information\n";
	outputStream << "Top left corner: (" << position.x << ", " << position.y << ")\n";
	outputStream << "Size: (" << size.x << ", " << size.y << ")\n";
	outputStream << "Speed: (" << obstacle.dx << ", " << obstacle.dy << ")\n";
	return outputStream;
};