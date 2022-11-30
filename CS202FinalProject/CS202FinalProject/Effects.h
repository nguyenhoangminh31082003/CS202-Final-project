#pragma once

#include "Effect.h"

class Effects {
private:

	std::vector<Effect*> effects;

	void clearAllEffects();

public:

	Effects();

	~Effects();

	void update();

	int getNumberOfEffects() const;

	void render(sf::RenderTarget * const target) const;

};