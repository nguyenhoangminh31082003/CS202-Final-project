#pragma once

#include "Effect.h"
#include "GameOptions.h"
class Effects {
private:

	std::vector<Effect*> effects;
	GameOptions* gameOptions;

public:

	Effects();

	~Effects();

	void addNewEffect(Effect * const effect);

	bool checkEmpty() const;

	void update();

	int getNumberOfEffects() const;

	void clearAllEffects();

	void render(sf::RenderTarget * const target) const;

	void takeGameOptions(GameOptions* gameOptions);

	friend std::ostream& operator << (std::ostream &outputStream, const Effects &effects);

};