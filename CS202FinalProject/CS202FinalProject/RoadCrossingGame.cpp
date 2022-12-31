#include <fstream>
#include <iostream>
#include <cassert>

#include "Helper.h"
#include "GrassRoad.h"
#include "Scoreboard.h"
#include "SidewalkRoad.h"
#include "RoadCrossingGame.h"
#include "FreezeEffect.h"
#include "ToBeContinuedEffect.h"
#include "CongratulationEffect.h"
#include "RobotoFonts.h"

void RoadCrossingGame::clearRoads() {
	while (!(this->roads).empty()) {
		delete (this->roads).back();
		(this->roads).pop_back();
	}
};

void RoadCrossingGame::initializePlayer() {
	(this->player).setPosition(500, 100);

	this->generalPosition = sf::Vector2f(500, 0);

	(this->player).setSpeed(100);
};

void RoadCrossingGame::initializeLevel() {
	(this->levelID) = 0;
	this->updateLevel(this->levelID);
};

void RoadCrossingGame::initializeTimer() {
	//(this -> player) = Player("Data/Images/player.png");
	(this->timer).stop();
	(this->timer).run();
	(this->gameInformationDisplay).setPosition(10, 0);
};

void RoadCrossingGame::setPositionsOfRoads() {
	double dy = 100;
	for (Road * &road : (this->roads)) {
		road -> movePositionVertically(dy);
		std::cerr << "Position of road is set to 0 " << dy << '\n';
		dy += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(sf::RenderWindow &window): window(window), player("../Resources/Object/Player/player.png", 4, 0.3f, 5), dTime(0.0){
	// Load car models
	//carModels.resize(MAX_NUM_CAR_MODELS);
	int i = 0;
	do {
		carModels.push_back(sf::Texture());
		std::string model_file("../Resources/Object/Obstacles/Cars/car_" + std::to_string(i) + ".png");
		std::cerr << model_file << "\n";
		if (!carModels[i].loadFromFile(model_file)) {
			carModels.pop_back();
			break;
		}
		++i;
	} while (true);
	// Load animal models
	i = 0;
	do {
		animalModels.push_back(sf::Texture());
		std::string model_file("../Resources/Object/Obstacles/Animals/animal_" + std::to_string(i) + ".png");
		std::cerr << model_file << "\n";
		if (!animalModels[i].loadFromFile(model_file)) {
			animalModels.pop_back();
			break;
		}
		++i;
	} while (true);

	this->initializeLevel();
	this->initializePlayer();
	this->initializeTimer();
	this->status = GAME_STATUS::CURRENT_PLAYED;
};

RoadCrossingGame::RoadCrossingGame(sf::RenderWindow& window, const bool savedOldGame): window(window), player("../Resources/Object/Player/player.png", 4, 1, 5) {
	// Load car models
	//carModels.resize(MAX_NUM_CAR_MODELS);
	int i = 0;
	do {
		carModels.push_back(sf::Texture());
		if (!carModels[i].loadFromFile("../Resources/Object/Obstacles/Cars/car_" + std::to_string(i) + ".png")) {
			carModels.pop_back();
			break;
		}
		++i;
	} while (true);

	i = 0;
	do {
		animalModels.push_back(sf::Texture());
		std::string model_file("../Resources/Object/Obstacles/Animals/animal_" + std::to_string(i) + ".png");
		std::cerr << model_file << "\n";
		if (!animalModels[i].loadFromFile(model_file)) {
			animalModels.pop_back();
			break;
		}
		++i;
	} while (true);

	this->initializeLevel();
	this->initializePlayer();
	this->initializeTimer();
	this->status = GAME_STATUS::CURRENT_PLAYED;
	if (savedOldGame)
		this->readGameFromTextFile();
};

RoadCrossingGame::~RoadCrossingGame() {
	this->clearRoads();
};

/*

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
*/

bool RoadCrossingGame::updateLevel(const int newLevelID) {
	//(this->levelID) = newLevelID;
	const std::string path = "Data/Levels/level_" + Helper::convertIntToString(newLevelID) + ".txt";
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		double speed;
		std::string roadType;
		int numberOfRoads, numberOfObstacles;
		
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		this->clearRoads();
		(this->roads).resize(numberOfRoads + 2, nullptr);
		
		(this->roads).front() = new SidewalkRoad();
		(this->roads).back() = new SidewalkRoad();
		
		for (int i = 1; i <= numberOfRoads; ++i) {
			Road*& road = (this->roads)[i];
			inputFile >> roadType;
			std::cerr << "Road type: " << roadType << '\n';
			if (roadType == "VehicleRoad") {
				inputFile >> numberOfObstacles >> speed;
				//std::assert(numberOfObstacles >= 1);
				road = new VehicleRoad(numberOfObstacles, speed, this->carModels);
			}
			else if (roadType == "GrassRoad")
			{
				inputFile >> numberOfObstacles >> speed;
				road = new GrassRoad(numberOfObstacles, speed, this->animalModels);
			}
			else if (roadType == "SidewalkRoad")
				road = new SidewalkRoad();
			else
				road = new SidewalkRoad();
		}
		this->setPositionsOfRoads();
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}

void RoadCrossingGame::render(sf::RenderTarget * const window) {
	for (Road *& road : (this->roads))
		road -> render(window);
	(this->player).render(window);
	(this->gameInformationDisplay).render(window);
	(this->effects).render(window);
};

void RoadCrossingGame::update() {

	sf::Vector2f acceleration(0, 0);
	const float dAcc = 2.f;

	(this->effects).update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves up" << '\n';
			acceleration.y -= dAcc;
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves down" << '\n';
			acceleration.y += dAcc;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves left" << '\n';
			acceleration.x -= dAcc;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
			std::cerr << "Player moves right" << '\n';
			acceleration.x += dAcc;
		}

	(this->player).velocity += acceleration;

	dTime = (this->timer).getRecordTime();

	if ((this->status) == CURRENT_PLAYED) {
		for (Road * &road : (this->roads)) {
			if (road->checkCollision(this->player)) {
				this->status = GAME_STATUS::LOSE;
				(this->player).stop();
				(this->timer).stopTemporarily();
				(this->effects).addNewEffect(new ToBeContinuedEffect());
				return;
			}
			road -> update(dTime);
		}

		//dTime = (this->timer).getRecordTime();

		const sf::Vector2f previousPosition((this -> player).getPosition());

		(this->player).move(dTime, 100, 1000, 0, 1500);

		const sf::Vector2f currentPosition((this->player).getPosition()), delta = currentPosition - previousPosition;

		(this->generalPosition) += delta;

		if ((this->generalPosition).y > 400 && 
			(this -> generalPosition).y < 100 * (((int)(this -> roads).size()) - 5) &&
			!Helper::checkEqual(delta.y, 0)) {
			for (Road*& road : (this->roads))
				road->movePositionVertically(-delta.y);
			(this->player).setPosition(sf::Vector2f(currentPosition.x, previousPosition.y));
		}

		
		if (Helper::checkGreaterOrEqual((this -> generalPosition).y, 100 * (((int)(this->roads).size()) - 1))) {
			this->status = GAME_STATUS::WIN;
			(this->player).stop();
			(this->timer).stopTemporarily();
			Scoreboard().saveScore(this -> levelID, (this -> timer).getRecordTime());
			(this->effects).addNewEffect(new CongratulationEffect(((this -> levelID) + 1) % 10 + 1));
			return;
		}
		
		(this->gameInformationDisplay).setContent((this->timer).getRecordTime(), 1 + (this -> levelID));
	}
};

bool RoadCrossingGame::saveGameToTextFile() {
	return this -> saveGameToTextFile("Data/SaveGame/saveGame.txt");
};

bool RoadCrossingGame::saveGameToTextFile(const std::string &path) {
	std::ofstream outputFile(path.c_str());
	const bool result = outputFile.is_open();
	if (result) {
		outputFile << (this->levelID) << '\n' << (this -> status) << '\n';
		for (Road * const & road : (this->roads))
			road -> saveToTextFile(outputFile);
		(this->player).saveToTextFile(outputFile);
		outputFile << (this -> generalPosition).x << ' ' << (this -> generalPosition).y << '\n';
		outputFile << (this->timer).getRecordTime() << '\n';
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

};

bool RoadCrossingGame::readGameFromTextFile() {
	return this->readGameFromTextFile("Data/SaveGame/saveGame.txt");;
};

bool RoadCrossingGame::readGameFromTextFile(const std::string& path) {
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		int status;
		double recordTime;
		std::string roadType;

		(this->effects).clearAllEffects();

		inputFile >> (this->levelID) >> status;

		(this->status) = (GAME_STATUS)status;

		if ((this->status) == GAME_STATUS::WIN) {
			(this->effects).addNewEffect(new CongratulationEffect(((this -> levelID) + 1) % 10 + 1));
			std::cerr << "Congratulation effect is added\n";
		} else if ((this->status) == GAME_STATUS::LOSE) {
			std::cerr << "To Be Continued effect is added\n";
			(this->effects).addNewEffect(new ToBeContinuedEffect());
		} else if ((this->status) == GAME_STATUS::PAUSED) {
			std::cerr << "Freeze effect is added\n";
			(this->effects).addNewEffect(new FreezeEffect("\tThe game is currently paused\n"
														  "\t\t> To load a game from a file, please type the path in the text text\n"
														  "\t\t\tand press enter to load the game from the entered path\n"));
		}
		
		//this->clearRoads();
		this->updateLevel(this->levelID);

		for (Road* & road : (this->roads)) {
			delete road;
			inputFile >> roadType;
			std::cerr << "Road type: " << roadType << '\n';
			if (roadType == "VehicleRoad") {
				road = new VehicleRoad(this -> carModels);
			} else if (roadType == "GrassRoad")
				road = new GrassRoad(this -> animalModels);
			else if (roadType == "SidewalkRoad")
				road = new SidewalkRoad();
			else
				road = new SidewalkRoad();
			road->readFromTextFile(inputFile);
		}
		
		(this->player).readFromTextFile(inputFile);

		(this->player).stop();
		
		inputFile >> (this -> generalPosition).x >> (this -> generalPosition).y >> recordTime; 
		(this->timer).setRecordTime(recordTime);
		
		std::cerr << (this->status) << '\n';
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
};

GAME_STATUS RoadCrossingGame::getGameStatus() const {
	return this->status;
};

void RoadCrossingGame::pauseGame() {
	if ((this->status) == GAME_STATUS::CURRENT_PLAYED) {
		(this->effects).clearAllEffects();
		this->status = GAME_STATUS::PAUSED;
		(this->timer).stopTemporarily();
		(this->effects).addNewEffect(new FreezeEffect("\tThe game is currently paused\n"
													  "\t\t> To load a game from a file, please type the path in the text text\n"
													  "\t\t\tand press enter to load the game from the entered path\n"));
	}
};

void RoadCrossingGame::continueGame() {
	if ((this->status) == GAME_STATUS::PAUSED) {
		(this->effects).clearAllEffects();
		this->status = GAME_STATUS::CURRENT_PLAYED;
		(this->timer).run();
	}
};

void RoadCrossingGame::resetCurrentLevel() {
	this->initializePlayer();
	this->initializeTimer();
	this->status = GAME_STATUS::CURRENT_PLAYED;
	this->updateLevel(this -> levelID);
	(this->effects).clearAllEffects();
};

void RoadCrossingGame::moveNextLevel() {
	this->levelID = ((this->levelID) + 1) % 10;
 	this->resetCurrentLevel();
};

double RoadCrossingGame::getRecordTime() {
	return (this->timer).getRecordTime();
};