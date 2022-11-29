#include <cmath>

#include "SoundWaveExplosionEffect.h"
#include "Helper.h"

SoundWaveExplosionEffect::SoundWaveExplosionEffect() {
	/*
	this->redSpeed = 0;
	this->blueSpeed = 0;
	this->greenSpeed = 0;
	*/
	this->radius = 0;
	this->expandingSpeed = 0;
	this->radiusBound = 0;
	(this->position).x = 0;
	(this->position).y = 0;
	this->alphaSpeed = 0;
	(this -> circle).setFillColor(sf::Color::Transparent);
	(this -> circle).setPointCount(50);
};

SoundWaveExplosionEffect::~SoundWaveExplosionEffect() {};

void SoundWaveExplosionEffect::setCenterPosition(const sf::Vector2f& position) {
	this->position = position;
	(this->circle).setPosition(position.x - (this -> radius), position.y - (this -> radius));
};

void SoundWaveExplosionEffect::update() {
	(this->radius) += (this -> expandingSpeed);
	if (this->checkFinished())
		return;
	sf::Color color = (this -> circle).getOutlineColor();
	(this->circle).setRadius(this -> radius);
	(this->circle).setPosition((this -> position).x - (this -> radius), (this->position).y - (this->radius));
	color.a = std::max(color.a - (this -> alphaSpeed), 0.0);
	(this->circle).setOutlineColor(color);
}

bool SoundWaveExplosionEffect::checkFinished() const {
	return (this->radius) > (this->expandingSpeed);
};

void SoundWaveExplosionEffect::render(sf::RenderTarget* const target) {
	target->draw(this -> circle);
};

void SoundWaveExplosionEffect::setColor(const sf::Color color) {
	(this->circle).setOutlineColor(color);
};

void SoundWaveExplosionEffect::setThickness(const double thickness) {
	(this->circle).setOutlineThickness(std::max(0.0, thickness));
};