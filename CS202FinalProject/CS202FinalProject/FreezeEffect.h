#pragma once

#include "Effect.h"

class FreezeEffect : public Effect {
private:

	sf::RectangleShape theme;
	sf::Texture texture;
	sf::RectangleShape box;
	sf::Font font;
	sf::Text text;

public:

	FreezeEffect(const std::string &content);

	~FreezeEffect();

	bool checkFinished() const;

	void update();

	void render(sf::RenderTarget* const target);

};