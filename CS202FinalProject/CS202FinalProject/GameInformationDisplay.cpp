#include <sstream>
#include <iomanip>

#include "GameInformationDisplay.h"
#include "Helper.h"

GameInformationDislay::GameInformationDislay() {
	(this->font).loadFromFile("Data/Fonts/Roboto/Roboto-Black.ttf");
	(this->text).setFont(this -> font);
	(this->text).setCharacterSize(30);
	(this->text).setFillColor(sf::Color::White);
};

void GameInformationDislay::render(sf::RenderTarget* const target) const {
	target -> draw(this -> text);
};

void GameInformationDislay::setContent(const double time, const int levelID) {
	std::stringstream ss;
	ss.setf(std::ios::fixed, std::ios::floatfield);
	ss.precision(3);
	ss << "Time:\n" << time << " seconds\t\t\t\tLevel: " << levelID;
	(this->text).setString(ss.str());
};

void GameInformationDislay::setPosition(const double x, const double y) {
	(this->text).setPosition(x, y);
};