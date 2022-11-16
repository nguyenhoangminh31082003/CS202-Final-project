#pragma once

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Audio/Sound.hpp>

class Player {
private:
	sf::Sound sound;
	sf::Sprite model;
	sf::Texture texture;
	double speed;

public:
	//----------Constructors--------------------//
	Player();
	Player(const std::string &model_file_path);


	//----------Member Functions---------------//

	//
	void render(sf::RenderTarget* const rdTarget) const;

	// Set the object's speed
	bool setSpeed(double speed);
	// Returns the object's speed
	double getSpeed() const;
	// Set the object's position
	void setPosition(const sf::Vector2f pos);
	void setPosition(float X, float Y);
	// Get the object's position
	sf::Vector2f getPosition() const;

	// Check collision between 2 objects
	bool checkCollision(const Player& other) const;

	// Object's Movement functions
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	bool moveLeft(const double lowerBound, const double upperBound);
	bool moveRight(const double lowerBound, const double upperBound);
	bool moveUp(const double lowerBound, const double upperBound);
	bool moveDown(const double lowerBound, const double upperBound);
	
	double getHeight() const;
	double getWidth() const;
};

