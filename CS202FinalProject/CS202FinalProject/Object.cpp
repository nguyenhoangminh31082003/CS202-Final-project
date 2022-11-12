#include "Object.h"

//----------Constructors------------------------------//
Object::Object(std::string model_file_path): speed(0) {
	texture.loadFromFile(model_file_path); // k is for debugging file path
	model.setTexture(texture, true);
}

//----------Member Functions-------------------------//
void Object::render(sf::RenderTarget* const rdTarget) {
	rdTarget->draw(model);
}

bool Object::setSpeed(double speed) {
	this->speed = speed;
	return true;
}

void Object::setPosition(const sf::Vector2f pos) {
	model.setPosition(pos);
}

void Object::setPosition(float X, float Y) {
	model.setPosition(X, Y);
}

double Object::getSpeed() const {
	return this -> speed;
}

sf::Vector2f Object::getPosition() {
	return model.getPosition();
}

bool Object::CheckCollision(const Object& other) const {
	return model.getGlobalBounds().intersects(other.model.getGlobalBounds());
}

void Object::moveLeft() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x -= speed;
	model.setPosition(new_pos);
}

void Object::moveRight() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x += speed;
	model.setPosition(new_pos);
}

void Object::moveUp() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y -= speed;
	model.setPosition(new_pos);
}

void Object::moveDown() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y += speed;
	model.setPosition(new_pos);
}