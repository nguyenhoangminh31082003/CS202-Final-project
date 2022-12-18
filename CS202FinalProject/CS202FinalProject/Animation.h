#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include <vector>
#include <iostream>

class Animation {
private:
	std::vector<sf::IntRect> frames; // stores the rects covering the frames
	float frameTime; // time for each frames, in this Game assume equal
	int cur_frame; // index of current frame
	double cur_frame_time; // calculate current frame's time to determine if it is time to switch frame
public:
	Animation();
	Animation(const std::vector<sf::IntRect>& frames, double duration);
	sf::IntRect& getCurrentFrame();
	void update(double dt);
};

