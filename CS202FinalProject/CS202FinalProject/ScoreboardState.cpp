#include "ScoreboardState.h"

void ScoreboardState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	
	this->backgroundTexture.loadFromFile("Data/Images/States/ScoreboardState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void ScoreboardState::initializeButtons() {
	this->buttons["BACK"] = new Button(0.6, 50, 900, "Data/Images/States/ScoreboardState/back");
	this->buttons["RESET"] = new Button(0.6, 1390, 900, "Data/Images/States/ScoreboardState/Replay_icon");

}

void ScoreboardState::loadScore()
{
	Scoreboard scoreboard;
	this->score = scoreboard.loadScoreboard();
}

void ScoreboardState::saveScore()
{
	Scoreboard scoreboard;
	scoreboard.saveScoreboard(this->score);
}

void ScoreboardState::resetScoreboard()
{
	for (int i = 0; i < score.size(); i++) score[i].clear();
	this->saveScore();
}

ScoreboardState::ScoreboardState(sf::RenderWindow* const window, std::stack<State*>* const states) : State(window, states) {
	this->loadScore();
	this->initializeBackground();
	this->initializeButtons();
};

ScoreboardState::ScoreboardState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) :State(window, states, gameOptions) {
	this->loadScore();
	this->initializeBackground();
	this->initializeButtons();
}

void ScoreboardState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);

	if (this->buttons["RESET"]->checkReleasedLeft()) {
		this->resetScoreboard();
		return;
	}

	if (this->buttons["BACK"]->checkReleasedLeft()) {
		this->endState();
		return;
	}
};

void ScoreboardState::update() {
	this->updateMousePosition();
};

void ScoreboardState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
	
	int titleWidth = 250, titleHeight = 60;
	int marginLeft = 100, marginTop = 50;
	int space = 100;
	sf::RectangleShape box(sf::Vector2f(titleWidth, titleHeight));
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineThickness(4);
	box.setOutlineColor(sf::Color::White);

	box.setFillColor(sf::Color::Black);
	box.setPosition(sf::Vector2f(marginLeft, marginTop));
	target->draw(box);

	box.setFillColor(sf::Color(255, 198, 55));
	box.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 1, marginTop));
	target->draw(box);

	box.setFillColor(sf::Color(170, 169, 173));
	box.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 2, marginTop));
	target->draw(box);

	box.setFillColor(sf::Color(176, 141, 87));
	box.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 3, marginTop));
	target->draw(box);

	sf::Font font;
	font.loadFromFile("Data/Fonts/Roboto/Roboto-Black.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Level");
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
	text.setPosition(sf::Vector2f(marginLeft + titleWidth / 2.0, marginTop + titleHeight / 2.0 - 10));
	target->draw(text);

	text.setString("1st");
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
	text.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 1 + titleWidth / 2.0, marginTop + titleHeight / 2.0 - 10));
	target->draw(text);

	text.setString("2nd");
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
	text.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 2 + titleWidth / 2.0, marginTop + titleHeight / 2.0 - 10));
	target->draw(text);

	text.setString("3rd");
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
	text.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * 3 + titleWidth / 2.0, marginTop + titleHeight / 2.0 - 10));
	target->draw(text);

	box.setSize(sf::Vector2f(titleWidth, titleHeight - 10));
	
	for (int i = 0; i < score.size(); i++)
	{
		box.setFillColor(sf::Color::Black);
		box.setPosition(sf::Vector2f(marginLeft, marginTop + 20 + (titleHeight + 10) * (i + 1)));
		target->draw(box);

		text.setString(to_string(i + 1));
		text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
		text.setPosition(sf::Vector2f(marginLeft + titleWidth / 2.0, marginTop + 20 + (titleHeight + 10) * (i + 1) + titleHeight / 2.0 - 15));
		target->draw(text);

		for (int j = 0; j < 3; j++)
		{
			box.setFillColor(sf::Color::Transparent);
			box.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * (j + 1), marginTop + 20 + (titleHeight + 10) * (i + 1)));
			target->draw(box);

			if (j < score[i].size()) text.setString(to_string(score[i][j]));
			else text.setString("-");
			text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2.0, text.getLocalBounds().height / 2.0));
			text.setPosition(sf::Vector2f(marginLeft + (titleWidth + space) * (j + 1) + titleWidth / 2.0, marginTop + 20 + (titleHeight + 10) * (i + 1) + titleHeight / 2.0 - 15));
			target->draw(text);
		}
	}
};

ScoreboardState::~ScoreboardState() {
	Scoreboard scoreboard;
	scoreboard.saveScoreboard(this->score);
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
}