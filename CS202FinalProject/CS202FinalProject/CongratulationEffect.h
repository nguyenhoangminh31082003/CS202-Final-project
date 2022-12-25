#pragma once

#include "Effect.h"

class CongratulationEffect : public Effect {
private:

	sf::RectangleShape theme;
	sf::Texture texture;
	sf::RectangleShape box;
	sf::Font font;
	sf::Text text;

public:

	CongratulationEffect(const int nextLevel);

	~CongratulationEffect();

	bool checkFinished() const;

	void update();

	void render(sf::RenderTarget* const target);

};