#include "SettingState.h"



void SettingState::initializeBackground() {
	this->background.setSize(sf::Vector2f(1500, 1000));
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("Data/Images/States/SettingState/background.png");
	this->background.setTexture(&this->backgroundTexture);
}

void SettingState::initializeButtons() {
	//this->buttons["MUSIC"] = new Button(1, 600, 200, "Data/Images/States/SettingState/music");
	this->buttons["BACK"] = new Button(1, 600, 400, "Data/Images/States/SettingState/back");
	if(this->gameOptions->checkMusic())
		this->MusicButton = new Button(1, 600, 200, "Data/Images/States/SettingState/music_on");
	else
		this->MusicButton = new Button(1, 600, 200, "Data/Images/States/SettingState/music_off");
}

SettingState::SettingState(sf::RenderWindow* window, std::stack<State*>* states) :State(window, states) {
	this->initializeBackground();
	this->initializeButtons();
}

SettingState::SettingState(sf::RenderWindow* window, std::stack<State*>* states, GameOptions* gameOptions) :State(window, states, gameOptions) {
	this->initializeBackground();
	this->initializeButtons();
}

SettingState::~SettingState() {
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
	delete this->MusicButton;
}

void SettingState::updateEvents() {
	if ((this->event).type == sf::Event::Closed)
		this->endState();

	for (auto& keyAndButton : (this->buttons))
		(keyAndButton.second)->updateEvent(this->event, this->mousePositionView);
	MusicButton->updateEvent(this->event, this->mousePositionView);

	if (this->MusicButton->checkReleasedLeft()) {
		if (this->gameOptions->checkMusic()) {
			this->gameOptions->setMuteMusic();
			delete this->MusicButton;
			this->MusicButton = new Button(1, 600, 200, "Data/Images/States/SettingState/music_off");
			this->saveMusicStatus(0);
		}
		else {
			this->gameOptions->setMusic();
			delete this->MusicButton;
			this->MusicButton = new Button(1, 600, 200, "Data/Images/States/SettingState/music_on");
			this->saveMusicStatus(1);
		}
	}

	if (this->buttons["BACK"]->checkReleasedLeft())
		this->endState();
}

void SettingState::update() {
	this->updateMousePosition();
}

void SettingState::render(sf::RenderWindow* const target) {
	target->draw(this->background);
	for (auto& it : this->buttons)
		it.second->render(target);
	MusicButton->render(target);
}

void SettingState::saveMusicStatus(int flag)
{
	std::ofstream fout;
	fout.open("Data/MusicFile/music.txt");
	if (fout.is_open())
	{
		fout << flag;
		fout.close();
	}
	else
	{
		std::cout << "Can not open Data/MusicFile/music.txt" << std::endl;
	}
}
