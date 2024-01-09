#pragma once
#include "Game.h"
#include "Board.h"
#include <functional>

class Player
{
private:	
	

public:
	static int pick;

	static Board boardG;
	void makeMove(std::function<void(int, std::vector<std::string>*)> func);

};

