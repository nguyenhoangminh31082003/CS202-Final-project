#include "FreezeEffect.h"
#include "Helper.h"

FreezeEffect::FreezeEffect(const std::string& content) {
	(this->texture).loadFromFile("Data/images/States/GameState/congratulation.png");
	(this->box).setSize(sf::Vector2f(1500, 600));
	(this->box).setPosition(sf::Vector2f(0, 200));
	(this->box).setFillColor(sf::Color(43, 113, 205)/*dark blue*/);
	(this->theme).setFillColor(sf::Color(124, 255, 252, 100)/*cyan*/);
	(this->theme).setSize(sf::Vector2f(1500, 1000));
	(this->font).loadFromFile("Data/fonts/Roboto/Roboto-Thin.ttf");
	(this->text).setFont(this->font);
	(this->text).setString(content);
	(this->text).setFillColor(sf::Color::White);
	(this->text).setCharacterSize(40);
	(this->text).setPosition(sf::Vector2f(0, 200));
	music.setLoop(true);
	music.openFromFile("Data/Music/Freeze.ogg");
	this->music.setVolume(20);
	this->music.play();
};

FreezeEffect::~FreezeEffect() {};

bool FreezeEffect::checkFinished() const {
	return false;
};

void FreezeEffect::update() {};

void FreezeEffect::render(sf::RenderTarget* const target) {
	target->draw(this->theme);
	target->draw(this->box);
	target->draw(this->text);
};

std::ostream& operator << (std::ostream& outputStream, const FreezeEffect& freezeEffect) {
	return outputStream << "FreezeEffect({characterSize = " << freezeEffect.text.getCharacterSize() << "})";
};