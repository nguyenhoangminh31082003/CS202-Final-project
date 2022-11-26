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

/*
bool Player::checkCollision(const Player& other) const {
	return model.getGlobalBounds().intersects(other.model.getGlobalBounds());
}
*/
/*
bool Player::checkCollision(const Obstacle& obstacle) const {
	return (this -> model).getGlobalBounds().intersects(obstacle.getBounds());
};
*/

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

bool Player::moveLeft(const double lowerBound, const double upperBound) {
	sf::Vector2f newPosition(model.getPosition());
	newPosition.x -= speed;
	if (newPosition.x < lowerBound || newPosition.x + (this->getWidth()) > upperBound)
		return false;
	model.setPosition(newPosition);
	return true;
};

bool Player::moveRight(const double lowerBound, const double upperBound) {
	sf::Vector2f newPosition(model.getPosition());
	newPosition.x += speed;
	if (newPosition.x < lowerBound || newPosition.x + (this->getWidth()) > upperBound)
		return false;
	model.setPosition(newPosition);
	return true;
};

bool Player::moveUp(const double lowerBound, const double upperBound) {
	sf::Vector2f newPosition(model.getPosition());
	newPosition.y -= speed;
	if (newPosition.y < lowerBound || newPosition.y + (this->getHeight()) > upperBound)
		return false;
	model.setPosition(newPosition);
	return true;
};

bool Player::moveDown(const double lowerBound, const double upperBound) {
	sf::Vector2f newPosition(model.getPosition());
	newPosition.y += speed;
	if (newPosition.y < lowerBound || newPosition.y + (this->getHeight()) > upperBound)
		return false;
	model.setPosition(newPosition);
	return true;
};

double Player::getHeight() const {
	return (this->model).getGlobalBounds().height;
};
double Player::getWidth() const {
	return (this->model).getGlobalBounds().width;
};

sf::FloatRect Player::getBounds() const {
	return (this->model).getGlobalBounds();
};