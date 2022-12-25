#include "CongratulationEffect.h"
#include "Helper.h"

CongratulationEffect::CongratulationEffect(const int nextLevel) {
	(this->texture).loadFromFile("Data/images/States/GameState/congratulation.png");
	(this->box).setSize(sf::Vector2f(1500, 600));
	(this->box).setPosition(sf::Vector2f(0, 200));
	(this->box).setFillColor(sf::Color(246, 68, 211)/*pink*/);
	(this->theme).setFillColor(sf::Color(255, 0, 127, 100));
	(this->theme).setSize(sf::Vector2f(1500, 1000));
	(this->font).loadFromFile("Data/fonts/Roboto/Roboto-Thin.ttf");
	(this->text).setFont(this -> font);
	(this->text).setString("Congratulation on passing the level!!!\n"
						   "Press 'Y' to continue with level " + Helper::convertIntToString(nextLevel) + " or\n" +
						   "click the \"Replay\" to replay the level");
	(this->text).setFillColor(sf::Color::White);
	(this->text).setCharacterSize(80);
	(this->text).setPosition(sf::Vector2f(0, 300));
};

CongratulationEffect::~CongratulationEffect() {};

bool CongratulationEffect::checkFinished() const {
	return false;
};

void CongratulationEffect::update() {};

void CongratulationEffect::render(sf::RenderTarget* const target) {
	target->draw(this->theme);
	target->draw(this->box);
	target->draw(this -> text);
};