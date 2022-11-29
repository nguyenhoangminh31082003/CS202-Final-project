#pragma once

#include <array>

#include "Effect.h"

class SoundWaveExplosionEffect : public Effect {
private:

	double expandingSpeed, /*redSpeed, blueSpeed, greenSpeed, */radius, radiusBound, alphaSpeed;
	sf::Vector2f position;
	sf::CircleShape circle;

public:
	
	SoundWaveExplosionEffect();

	~SoundWaveExplosionEffect();

	void setCenterPosition(const sf::Vector2f &position);

	void setColor(const sf::Color color);

	void setThickness(const double thickness);

	bool checkFinished() const;

	void update();

	void render(sf::RenderTarget* const target);

};