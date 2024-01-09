#pragma once
#include <iostream>
#include <vector>


class Game
{
private:
	int m, lvl;
	bool end = false;
	bool p1 = false;
	bool p2 = false;
	bool botW = false;

	void mode();
	void congratulation();
	void botmode();
	void local();

public:
    void startGame();
};

