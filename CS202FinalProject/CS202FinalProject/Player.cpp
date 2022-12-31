#include "Player.h"

//----------Constructors------------------------------//
Player::Player() :
	speed(0.0), velocity(sf::Vector2f(0.0, 0.0)), currentAnimation(idle), 
	hitbox(sf::RectangleShape(sf::Vector2f(25.0f, 40.0f))) 
{}

Player::Player(const std::string& model_folder_path, int num_frames, float anim_duration, int num_anims):
	speed(0.0), velocity(sf::Vector2f(0.0, 0.0)),
	currentAnimation(idle),
	hitbox(sf::RectangleShape(sf::Vector2f(25.0f, 40.0f))) {
	texture.loadFromFile(model_folder_path);
	model.setTexture(texture, true);
	/*
		Load animations
	*/
	sf::Vector2u tt_size = texture.getSize();
	unsigned frame_width = tt_size.x / num_frames;
	unsigned frame_height = tt_size.y / num_frames;

	std::vector<sf::IntRect> frames;

	for (int j = 0; j < num_frames; j++)
		frames.insert(frames.begin() + j, sf::IntRect(frame_width * j, frame_height, frame_width, frame_height));
	animations.insert(animations.begin(), Animation(frames, anim_duration));
	frames.clear();

	for (int i = 1; i < num_anims; i++) {
		for (int j = 0; j < num_frames; j++)
			frames.insert(frames.begin() + j, sf::IntRect(frame_width * j, frame_height * (i-1), frame_width, frame_height));
		animations.insert(animations.begin() + i, Animation(frames, anim_duration));
		frames.clear();
	}

	currentAnimation = idle;
	model.setTextureRect(animations[idle].getCurrentFrame());
	hitbox.setPosition(model.getPosition().x + model.getGlobalBounds().width / 2 - hitbox.getGlobalBounds().width / 2,
					   model.getPosition().y + model.getGlobalBounds().height / 2 - hitbox.getGlobalBounds().height / 2);

	// For debug

	/*
	std::cerr << model.getPosition().x << " " << model.getPosition().y << "\n";
	std::cerr << model.getGlobalBounds().width / 2 << " " << model.getGlobalBounds().height / 2 << "\n";
	std::cerr << hitbox.getGlobalBounds().width / 2 << " " << hitbox.getGlobalBounds().height / 2 << "\n";
	std::cerr << model.getPosition().x + model.getGlobalBounds().width / 2 - hitbox.getGlobalBounds().width / 2 << "\n";
	std::cerr << model.getPosition().y + model.getGlobalBounds().height / 2 - hitbox.getGlobalBounds().height / 2 << "\n";
	system("pause");
	*/
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Green);
	hitbox.setOutlineThickness(1);
	
}

//----------Member Functions-------------------------//
void Player::render(sf::RenderTarget* const rdTarget) const {
	rdTarget->draw(model);

	// For debug
	sf::RectangleShape sprite_box(sf::Vector2f(model.getGlobalBounds().width, model.getGlobalBounds().height));
	sprite_box.setPosition(model.getPosition().x, model.getPosition().y);
	sprite_box.setFillColor(sf::Color::Transparent);
	sprite_box.setOutlineColor(sf::Color::Red);
	sprite_box.setOutlineThickness(1);
	rdTarget->draw(sprite_box);

	rdTarget->draw(hitbox);
}

bool Player::setSpeed(double speed) {
	this->speed = speed;
	return true;
}

void Player::setPosition(const sf::Vector2f pos) {
	model.setPosition(pos);
	setHitboxPosition();
}

void Player::setPosition(float X, float Y) {
	model.setPosition(X, Y);
	setHitboxPosition();
}

double Player::getSpeed() const {
	return this -> speed;
}

sf::Vector2f Player::getPosition() const {
	return (this -> model).getPosition();
}

/*
bool Player::checkCollision(const Player& other) const {
	return model.getGlobalBounds().intersects(other.model.getGlobalBounds());
}
*/

bool Player::checkCollision(const Obstacle& obstacle) const {
	return (this -> hitbox).getGlobalBounds().intersects(obstacle.getBounds());
};

void Player::setHitboxPosition()
{
	hitbox.setPosition(model.getPosition().x + model.getGlobalBounds().width / 2 - hitbox.getGlobalBounds().width / 2,
					   model.getPosition().y + model.getGlobalBounds().height / 2 - hitbox.getGlobalBounds().height / 2);
}


void Player::moveLeft() {
	currentAnimation = move_left;
	model.setTextureRect(animations[currentAnimation].getCurrentFrame());
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x -= speed;
	model.setPosition(new_pos);
	setHitboxPosition();
}

void Player::moveRight() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.x += speed;
	model.setPosition(new_pos);
	setHitboxPosition();
}

void Player::moveUp() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y -= speed;
	model.setPosition(new_pos);
	setHitboxPosition();
}

void Player::moveDown() {
	sf::Vector2f new_pos(model.getPosition());
	new_pos.y += speed;
	model.setPosition(new_pos);
	setHitboxPosition();
}

bool Player::moveLeft(const double lowerBound, const double upperBound) {

	currentAnimation = move_left;
	model.setTextureRect(animations[currentAnimation].getCurrentFrame());

	sf::Vector2f newPosition(model.getPosition());
	newPosition.x -= speed;
	if (newPosition.x < lowerBound || newPosition.x + (this->getWidth()) > upperBound)
		return false;
	model.setPosition(newPosition);
	setHitboxPosition();
	return true;
};

bool Player::moveRight(const double lowerBound, const double upperBound) {

	currentAnimation = move_right;
	model.setTextureRect(animations[currentAnimation].getCurrentFrame());

	sf::Vector2f newPosition(model.getPosition());
	newPosition.x += speed;
	if (newPosition.x < lowerBound || newPosition.x + (this->getWidth()) > upperBound)
		return false;
	model.setPosition(newPosition);
	setHitboxPosition();
	return true;
};

bool Player::moveUp(const double lowerBound, const double upperBound) {


	currentAnimation = move_up;
	model.setTextureRect(animations[currentAnimation].getCurrentFrame());

	sf::Vector2f newPosition(model.getPosition());
	newPosition.y -= speed;
	if (newPosition.y < lowerBound || newPosition.y + (this->getHeight()) > upperBound)
		return false;
	model.setPosition(newPosition);
	setHitboxPosition();
	return true;
};

bool Player::moveDown(const double lowerBound, const double upperBound) {


	currentAnimation = move_down;
	model.setTextureRect(animations[currentAnimation].getCurrentFrame());

	sf::Vector2f newPosition(model.getPosition());
	newPosition.y += speed;
	if (newPosition.y < lowerBound || newPosition.y + (this->getHeight()) > upperBound)
		return false;
	model.setPosition(newPosition);
	setHitboxPosition();
	return true;
};

double Player::getHeight() const {
	return (this->hitbox).getGlobalBounds().height;
};
double Player::getWidth() const {
	return (this->hitbox).getGlobalBounds().width;
};

sf::FloatRect Player::getBounds() const {
	return (this->hitbox).getGlobalBounds();
};

void Player::saveToTextFile(std::ofstream& outputFile) const {
	outputFile << (this->speed) << ' ' 
		       << (this->model).getPosition().x << ' ' << (this->model).getPosition().y << ' '
		       << (this->hitbox).getPosition().x << ' ' << (this->hitbox).getPosition().y << '\n';
};

void Player::readFromTextFile(std::ifstream& inputFile) {
	sf::Vector2f position;
	inputFile >> (this->speed) >> position.x >> position.y;
	(this->model).setPosition(position);
	inputFile >> position.x >> position.y;
	(this->hitbox).setPosition(position);
};

std::ostream& operator << (std::ostream& outputStream, const Player& player) {
	const auto position = (player.model).getPosition();
	outputStream << "Obstacle information\n";
	outputStream << "Top left corner: (" << position.x << ", " << position.y << ")\n";
	outputStream << "Speed: " << player.speed << "\n";
	return outputStream;
};

bool Player::move(float dTime, const double lowerBoundY, const double upperBoundY, const double lowerBoundX, const double upperBoundX) {


	animations[currentAnimation].update(dTime);

	sf::Vector2f newPosition(model.getPosition());

	//std::cerr << "velocity x = " << velocity.x << "\n";
	//std::cerr << "velocity y = " << velocity.y << "\n";

	if (abs(velocity.x) > abs(velocity.y)) {
		if (velocity.x < 0) {
			currentAnimation = move_left;
			model.setTextureRect(animations[currentAnimation].getCurrentFrame());
		} else {
			currentAnimation = move_right;
			model.setTextureRect(animations[currentAnimation].getCurrentFrame());
		}
	} else {
		if (velocity.y < 0) {
			currentAnimation = move_up;
			model.setTextureRect(animations[currentAnimation].getCurrentFrame());
		} else {
			currentAnimation = move_down;
			model.setTextureRect(animations[currentAnimation].getCurrentFrame());
		}
	}

	newPosition.x += velocity.x;
	newPosition.y += velocity.y;
	velocity *= 0.5f;
	if (newPosition.y < lowerBoundY || newPosition.y + (this->getHeight()) > upperBoundY || newPosition.x < lowerBoundX || newPosition.x + (this->getWidth()) > upperBoundX)
		return false;
	model.setPosition(newPosition);
	setHitboxPosition();
	return true;
};

void Player::stop() {
	(this->velocity) = sf::Vector2f(0, 0);
};