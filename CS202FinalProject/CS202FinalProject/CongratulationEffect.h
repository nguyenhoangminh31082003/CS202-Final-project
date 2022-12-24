#pragma once

#include "Effect.h"

class CongratulationEffect : public Effect {
private:

	sf::RectangleShape theme;
	sf::Texture texture;
	sf::Sprite congratulationImage;

public:

	CongratulationEffect();

	~CongratulationEffect();

	bool checkFinished() const;

	void update();

	void render(sf::RenderTarget* const target);

};