#pragma once

#include "Effect.h"

class ToBeContinuedEffect : public Effect {
private:

	sf::RectangleShape theme;
	sf::Texture texture;
	sf::Sprite toBeContinuedImage;
	sf::Music music;

public:

	ToBeContinuedEffect();

	~ToBeContinuedEffect();

	bool checkFinished() const;

	void update();

	void render(sf::RenderTarget* const target);

};