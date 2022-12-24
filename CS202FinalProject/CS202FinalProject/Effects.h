#pragma once

#include "Effect.h"

class Effects {
private:

	std::vector<Effect*> effects;

public:

	Effects();

	~Effects();

	void addNewEffect(Effect * const effect);

	bool checkEmpty() const;

	void update();

	int getNumberOfEffects() const;

	void clearAllEffects();

	void render(sf::RenderTarget * const target) const;

	friend std::ostream& operator << (std::ostream &outputStream, const Effects &effects);

};