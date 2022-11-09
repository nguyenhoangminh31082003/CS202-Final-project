#pragma once

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Audio/Sound.hpp>

class Object
{
private:
	sf::Sound sound;
	sf::Sprite model;
	sf::Texture texture;
	double speed;
public:
	//----------Constructors--------------------//
	Object(std::string model_file_path);


	//----------Member Functions---------------//

	//
	void render(sf::RenderTarget* const rdTarget);

	// Set the object's speed
	bool setSpeed(double speed);
	// Returns the object's speed
	double getSpeed();
	// Set the object's position
	void setPosition(const sf::Vector2f pos);
	void setPosition(float X, float Y);
	// Get the object's position
	sf::Vector2f getPosition();

	// Check collision between 2 objects
	bool CheckCollision(const Object& other);

	// Object's Movement funcs
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	
};

