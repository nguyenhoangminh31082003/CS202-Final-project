#pragma once

#include "Animation.h"
#include "Obstacle.h"

class Animal :
    public Obstacle
{
private:
    Animation animation;
public:
    Animal(const double dx, const double dy, std::vector<sf::Texture> Models, int num_frames = 0, float anim_duration = 0.0, int num_anims = 1);
    Animal(std::ifstream &inputFile, const std::vector<sf::Texture> &Models, int num_frames, float anim_duration, int num_anims);

    void render(sf::RenderTarget* const window) const;
    void movePosition_wAnim(float dTime);
};
