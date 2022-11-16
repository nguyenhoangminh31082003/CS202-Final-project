#pragma once
//#include "GameState.h"
#include "State.h"
//#include "OptionsState.h"
#include "Button.h"
#include "ScoreBoardState.h"
#include "MainProgram.h"
#include <stack>
class MainMenuState : public State
{

private:

	sf::Texture backgroundTexture;
	sf::Sprite bgSprite;
	sf::RectangleShape background;
	sf::Font fontSquid;
	sf::Font font;
	ScoreBoardState 


	std::map<std::string, Button*> buttons;
	//std::map<std::string, Numbox*> numboxes;
	std::map<int, int> levelRows;
	std::map<int, int> levelCols;
	std::map<int, int> levelMines;

	bool lastPlay;
	short curLv;

	void initVariables();
	void initBackground();
	void initFonts();
	void initKeyBinds();
	void initButtons();
	void initNumboxes();
	void initData();
	void initRankTable();

	bool getInput(int& rows, int& cols, int& mines);
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, GameOptions* gameOptions);
	virtual ~MainMenuState();

	//void showInputConditions(sf::RenderTarget* target);

	void updateEvents();
	void updateInput(const float& dt);
	void updateButtons();
	void updateNumboxes();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void renderNumboxes(sf::RenderTarget* target);
	void render(sf::RenderTarget* target = nullptr);
};

