#include "Helper.h"
#include "RailwayRoad.h"

void RailwayRoad::resetTrainPosition() {
	sf::Vector2f position((this -> train).getPosition());
	//position.x = (this -> roadImage).getPosition().x - (this->train).getWidthOfImage();
	position.x = (this->roadImage).getPosition().x - (this->train).getWidth();
	(this->train).setPosition(position.x, position.y);
};

RailwayRoad::RailwayRoad(): status(RAILWAY_ROAD_STATUS::NO_TRAIN) {
	if ((this->texture).loadFromFile("Data/images/Roads/RailwayRoads/railway_road.png"))
		std::cerr << "Texture is loaded successfully\n";
	this->remainingTime = 100 + Helper::getRandomInteger(0, 1000);
	(this->roadImage).setTexture(this->texture, true);
	this->resetTrainPosition();
};

void RailwayRoad::movePositionVertically(const double dy) {
	(this->roadImage).move(sf::Vector2f(0, dy));
	(this->train).movePositionVertically(dy);
};

RailwayRoad::~RailwayRoad() {}

void RailwayRoad::render(sf::RenderTarget* const target) {
	target->draw(this->roadImage);
	if ((this->status) == RAILWAY_ROAD_STATUS::TRAIN_IS_RUNNING)
		(this -> train).render(target);
	else if ((this->status) == RAILWAY_ROAD_STATUS::TRAIN_IS_COMING) {
		sf::Color light(sf::Color::Yellow);
		sf::RectangleShape theme;
		theme.setPosition((this -> roadImage).getPosition());
		//light.a = abs(this->remaingTime) % 100 + 150;
		light.a = abs(this->remainingTime) % 100 + 50;
		theme.setFillColor(light);
		theme.setSize(sf::Vector2f(1500, 100));
		//theme.setSize(sf::Vector2f(50, 100));
		target->draw(theme);
	} else if ((this->status) == RAILWAY_ROAD_STATUS::NO_TRAIN) {
		sf::Color light(sf::Color::Green);
		sf::RectangleShape theme;
		theme.setPosition((this->roadImage).getPosition());
		//light.a = abs(this->remaingTime) % 100 + 150;
		light.a = abs(this->remainingTime) % 100 + 50;
		theme.setFillColor(light);
		theme.setSize(sf::Vector2f(1500, 100));
		//theme.setSize(sf::Vector2f(50, 100));
		target->draw(theme);
	}
};

void RailwayRoad::update(float dTime) {
	const double northY = (this->roadImage).getPosition().y,
			   	 southY = northY + (this->texture).getSize().y,
				 westX = (this->roadImage).getPosition().x,
				 eastX = (this->texture).getSize().x;
	if ((this->status) == RAILWAY_ROAD_STATUS::TRAIN_IS_RUNNING) {
		(this->train).movePosition();
		std::cerr << "Train position: " << (this->train).getPosition().x << ' ' << (this->train).getPosition().y << '\n';
		if ((this -> train).getXofWestBound() > eastX) {
			this->status = RAILWAY_ROAD_STATUS::NO_TRAIN;
			(this->train).endSound();
			this->remainingTime = 500 + Helper::getRandomInteger(0, 500);
		}
	} else if ((this->status) == RAILWAY_ROAD_STATUS::TRAIN_IS_COMING) {
		--(this->remainingTime);
		if ((this->remainingTime) < 0)
			this->status = RAILWAY_ROAD_STATUS::TRAIN_IS_RUNNING;
	} else if ((this->status) == RAILWAY_ROAD_STATUS::NO_TRAIN) {
		--(this->remainingTime);
		if ((this->remainingTime) < 0) {
			this->status = RAILWAY_ROAD_STATUS::TRAIN_IS_COMING;
			(this->train).startSound();
			this->remainingTime = 100 + Helper::getRandomInteger(0, 200);
			this->resetTrainPosition();
		} else
			(this->train).endSound();
	}
};

bool RailwayRoad::checkCollision(const Player& player) const {
	if ((this -> status) == RAILWAY_ROAD_STATUS::TRAIN_IS_RUNNING)
		return player.checkCollision(this -> train);
	return false;
};

void RailwayRoad::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << "RailwayRoad\n" << (this->roadImage).getPosition().x << ' ' << (this->roadImage).getPosition().y << '\n' << (this -> remainingTime) << '\n';
	(this->train).saveToTextFile(outputFile);
	outputFile << (this->status) << '\n';
};

void RailwayRoad::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	int status;
	inputFile >> position.x >> position.y >> (this -> remainingTime);
	this->setRoadPosition(position);
	(this->train).readFromTextFile(inputFile);
	inputFile >> status;
	this->status = (RAILWAY_ROAD_STATUS)(status);
	switch (this->status) {
		case RAILWAY_ROAD_STATUS::NO_TRAIN:
			(this->train).endSound();
			break;
		default:
			(this->train).startSound();
			break;
	}
};

void RailwayRoad::startSound() {
	switch (this->status) {
	case RAILWAY_ROAD_STATUS::NO_TRAIN:
		(this->train).endSound();
		break;
	default:
		(this->train).startSound();
		break;
	}
};

void RailwayRoad::endSound() {
	(this->train).endSound();
};

std::ostream& operator << (std::ostream& outputStream, const RailwayRoad& railwayRoad) {
	outputStream << "RailwayRoad({status = " << railwayRoad.status;
	return outputStream << "})";
};