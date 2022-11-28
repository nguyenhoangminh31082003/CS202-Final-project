#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Effect {
private:
public:

	Effect();
	virtual ~Effect();

	virtual bool checkFinished() const;
	virtual void update();
	virtual void render(sf::RenderTarget* const target) = 0;

};