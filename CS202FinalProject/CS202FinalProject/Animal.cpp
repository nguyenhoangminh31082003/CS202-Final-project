#include "Animal.h"

Animal::Animal(const double dx, const double dy, std::vector<sf::Texture> Models, int num_frames, float anim_duration, int num_anims) :
	Obstacle(dx, dy, Models) {
	sf::Vector2u tt_size = texture.getSize();
	unsigned frame_width = tt_size.x / num_frames;
	unsigned frame_height = tt_size.y;

	std::vector<sf::IntRect> frames;

	for (int i = 0; i < num_frames; i++)
	{
		frames.insert(frames.begin() + i, sf::IntRect(frame_width * i, 0, frame_width, frame_height));
	}

	animation = Animation(frames, anim_duration);

	this->model.setTextureRect(animation.getCurrentFrame());
	this->model.scale(2.0f, 2.0f);

	/*
	hitbox.setPosition(model.getPosition().x + model.getGlobalBounds().width / 2 - hitbox.getGlobalBounds().width / 2,
		model.getPosition().y + model.getGlobalBounds().height / 2 - hitbox.getGlobalBounds().height / 2);
	*/
}

Animal::Animal(std::vector<sf::Texture> Models, int num_frames, float anim_duration, int num_anims) : Obstacle(Models) {
	sf::Vector2u tt_size = texture.getSize();
	unsigned frame_width = tt_size.x / num_frames;
	unsigned frame_height = tt_size.y;

	std::vector<sf::IntRect> frames;

	for (int i = 0; i < num_frames; i++)
	{
		frames.insert(frames.begin() + i, sf::IntRect(frame_width * i, 0, frame_width, frame_height));
	}

	animation = Animation(frames, anim_duration);

	this->model.setTextureRect(animation.getCurrentFrame());
	this->model.scale(2.0f, 2.0f);

	/*
	hitbox.setPosition(model.getPosition().x + model.getGlobalBounds().width / 2 - hitbox.getGlobalBounds().width / 2,
		model.getPosition().y + model.getGlobalBounds().height / 2 - hitbox.getGlobalBounds().height / 2);
	*/
}

void Animal::movePosition_wAnim(float dTime)
{
	this->animation.update(dTime);
	this->model.setTextureRect(this->animation.getCurrentFrame());
	(this->model).move(dx, dy);
}

void Animal::render(sf::RenderTarget* const window) const {
	window->draw(this->model);
}

Animal::~Animal() {};