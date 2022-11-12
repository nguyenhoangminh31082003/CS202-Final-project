#include "Player.h"

//----------Constructors------------------------------//
Player::Player(): speed(0) {}

Player::Player(const std::string &model_file_path): speed(0) {
	texture.loadFromFile(model_file_path); // k is for debugging file path
	model.setTexture(texture, true);
}

//----------Member Functions-------------------------//
void Player::render(sf::RenderTarget* const rdTarget) const {
	rdTarget->draw(model);
}

bool Player::setSpeed(double speed) {
	this->speed = speed;
	return true;
}

void Player::setPosition(const sf::Vector2f pos) {
	model.setPosition(pos);
}

void Player::setPosition(float X, float Y) {
	model.setPosition(X, Y);
}

double Player::getSpeed() const {
	return this -> speed;
}

sf::Vector2f Player::getPosition() const {
	return (this -> model).getPosition();
}

bool Player::checkCollision(const Player& other) const {
	return model.getGlobalBounds().intersects(other.model.getGlobalBounds());
}

void Player::moveLeft() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x -= speed;
	model.setPosition(new_pos);
}

void Player::moveRight() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x += speed;
	model.setPosition(new_pos);
}

void Player::moveUp() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y -= speed;
	model.setPosition(new_pos);
}

void Player::moveDown() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y += speed;
	model.setPosition(new_pos);
}