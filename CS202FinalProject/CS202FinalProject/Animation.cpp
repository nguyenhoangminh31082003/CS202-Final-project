#include "Animation.h"

Animation::Animation():
	frameTime(0.0), cur_frame(0), cur_frame_time(0.0)
{
}
Animation::Animation(const std::vector<sf::IntRect>& frames, float duration)
{
	this->frames = frames;
	frameTime = duration / frames.size();
	cur_frame = 0;
	cur_frame_time = 0.0;
}

sf::IntRect& Animation::getCurrentFrame()
{
	return frames[cur_frame];
}

void Animation::update(float dt) {
	cur_frame_time += dt;
	while (cur_frame_time >= frameTime) {
		cur_frame_time -= frameTime;
		cur_frame = (cur_frame + 1) % frames.size();
	}
}