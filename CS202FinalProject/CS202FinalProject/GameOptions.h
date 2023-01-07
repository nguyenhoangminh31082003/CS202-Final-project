#pragma once
class GameOptions
{
private:
	bool isSound, isMusic, userWantsMusic;
public:
	GameOptions();
	virtual ~GameOptions();
	bool setSound();
	bool setMuteSound();
	bool setMusic();
	bool setMuteMusic();
	bool checkSound();
	bool checkMusic();
	void setUserWantsMusic(bool flag);
	bool checkUserWantsMusic();
};