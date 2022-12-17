#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

void RoadCrossingGame::clearRoads() {
	while (!(this->roads).empty()) {
		delete (this->roads).back();
		(this->roads).pop_back();
	}
};

void RoadCrossingGame::initializePlayer() {
	(this->player).setPosition(200, 400);
	(this->player).setSpeed(100);
	(this->rowID) = 4;
	(this->columnID) = 2;
};

void RoadCrossingGame::initializeLevel() {
	(this->levelID) = 0;
	this->updateLevel(this->levelID);
};

void RoadCrossingGame::initializeTimer() {
	//(this -> player) = Player("Data/Images/player.png");
	(this->timer).stop();
	(this->timer).run();
	(this->timerDisplay).setPosition(10, 0);
};

void RoadCrossingGame::setPositionsOfRoads() {
	sf::Vector2f position(300, 0);
	for (Road * &road : (this->roads)) {
		road -> setRoadPosition(position);
		std::cerr << "Position of road is set to " << position.x << ' ' << position.y << '\n';
		position.x += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(): player("../Resources/Object/Player/player.png", 4, 1, 5) {
	this->initializeLevel();
	this->initializePlayer();
	this->initializeTimer();
	this->status = GAME_STATUS::CURRENT_PLAYED;
};

RoadCrossingGame::~RoadCrossingGame() {
	this->clearRoads();
};

bool RoadCrossingGame::updateLevel(const int newLevelID) {
	//(this->levelID) = newLevelID;
	const std::string path = "Data/Levels/level_" + Helper::convertIntToString(newLevelID) + ".txt";
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		double speed;
		int numberOfRoads, numberOfObstacles;
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		this->clearRoads();
		(this -> roads).resize(numberOfRoads + 2);
		for (Road*& road : (this->roads))
			road = new Road;
		this -> setPositionsOfRoads();
		for (int i = 1; i <= numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
			if (numberOfObstacles > 0) {
				inputFile >> speed;
				(this->roads)[i] -> appendObstaclesWithSpeed(speed, numberOfObstacles);
			}
		}
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}

void RoadCrossingGame::render(sf::RenderTarget * const window) {
	for (Road *& road : (this->roads))
		road -> render(window);
	(this->player).render(window);
	(this->timerDisplay).render(window);
};

void RoadCrossingGame::update() {
	if ((this->status) == CURRENT_PLAYED) {
		for (Road * &road : (this->roads)) {
			if (road->checkCollision(this->player)) {
				this->status = GAME_STATUS::LOSE;
				(this->timer).stopTemporarily();
				return;
			}
			road -> update();
			this->player.move(0, 1500);
		}
		if (this->columnID == (this->roads).size() + 2) {
			this->status = GAME_STATUS::WIN;
			(this->timer).stopTemporarily();
			return;
		}
		(this->timerDisplay).setContent((this->timer).getRecordTime());
	}
};

bool RoadCrossingGame::saveGameToTextFile() {
	return this -> saveGameToTextFile("Data/SaveGame/saveGame.txt");
};

bool RoadCrossingGame::saveGameToTextFile(const std::string &path) {
	std::ofstream outputFile(path.c_str());
	const bool result = outputFile.is_open();
	if (result) {
		outputFile << (this->levelID) << '\n';
		for (Road * const & road : (this->roads))
			road -> saveToTextFile(outputFile);
		(this->player).saveToTextFile(outputFile);
		outputFile << rowID << ' ' << columnID << '\n' << (this->timer).getRecordTime() << '\n';
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	outputFile.close();
	return result;
};

void RoadCrossingGame::updateWithEvent(const sf::Event& event) {
	/*
	switch (event.type) {
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Up:
				if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
					std::cerr << "Player moves up" << '\n';
					--(this->rowID);
					(this->player).moveUp(0, 1000);
				}
				break;
		case sf::Keyboard::Down:
			if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
				std::cerr << "Player moves down" << '\n';
				++(this->rowID);
				(this->player).moveDown(0, 1000);
			}
			break;
		case sf::Keyboard::Left:
			if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
				std::cerr << "Player moves left" << '\n';
				--(this->columnID);
				(this->player).moveLeft(0, 1500);
			}
			break;
		case sf::Keyboard::Right:
			if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
				std::cerr << "Player moves right" << '\n';
				++(this->columnID);
				(this->player).moveRight(0, 1500);
			}
			break;
		}
		break;
	}
	*/

	sf::Vector2f acceleration;
	const float dAcc = 0.3f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves up" << '\n';
			//--(this->rowID);
			acceleration.y -= dAcc;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves down" << '\n';
			//++(this->rowID);
			acceleration.y += dAcc;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves left" << '\n';
			//--(this->columnID);
			acceleration.x -= dAcc;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves right" << '\n';
			//++(this->columnID);
			acceleration.x += dAcc;
		}

	this->player.velocity += acceleration;
};


bool RoadCrossingGame::readGameFromTextFile() {
	return this->readGameFromTextFile("Data/SaveGame/saveGame.txt");;
};

bool RoadCrossingGame::readGameFromTextFile(const std::string& path) {
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		double recordTime;

		inputFile >> (this->levelID);
		
		this->clearRoads();
		this->updateLevel(this->levelID);

		for (Road* const& road : (this->roads))
			road->readFromTextFile(inputFile);
		
		(this->player).readFromTextFile(inputFile);
		
		inputFile >> (this->rowID) >> (this->columnID) >> recordTime; 
		(this->timer).setRecordTime(recordTime);
	}
	else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
};

GAME_STATUS RoadCrossingGame::getGameStatus() const {
	return this->status;
};

void RoadCrossingGame::pauseGame() {
	if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
		this->status = GAME_STATUS::PAUSED;
		(this->timer).stopTemporarily();
	}
};

void RoadCrossingGame::continueGame() {
	if ((this->status) == GAME_STATUS::PAUSED) {
		this->status = GAME_STATUS::CURRENT_PLAYED;
		(this->timer).run();
	}
};

void RoadCrossingGame::resetCurrentLevel() {
	this->initializePlayer();
	this->initializeTimer();
	this->status = GAME_STATUS::CURRENT_PLAYED;
	this->updateLevel(this -> levelID);
};

double RoadCrossingGame::getRecordTime() {
	return (this->timer).getRecordTime();
};