#pragma once
#include "Player.h"

class BotPlayer : public Player
{
public:
	int lv;
	int botPick = -1;

	BotPlayer(int l) : lv(l) {}

	bool findWinningMove(int& move, std::vector<std::string>* map);

	bool blockOpponentWinningMove(int& move, std::vector<std::string>* map);

	void random();
	void medium();
	void hard();
	void chooser();
	void makeMove(std::function<void(int, std::vector<std::string>*)> func);


};

