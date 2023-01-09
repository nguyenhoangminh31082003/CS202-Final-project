#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <fstream>
#include <iostream>

#include "Obstacle.h"

class Cactus : public Obstacle {	
public:

	Cactus();

	~Cactus();

};