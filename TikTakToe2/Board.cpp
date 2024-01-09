#include "Board.h"
#include "Game.h"
#include "Player.h"
#include <string>

void Board::xses(int p, std::vector<std::string>* map)
{
	(*map)[(p - 1) * 2] = "X";
}

void Board::circles(int p, std::vector<std::string>* map)
{
	(*map)[(p - 1) * 2] = "O";
}

void Board::displayBoard()
{
	for (std::string ch : this->board)
	{
		std::cout << ch;
	}
	std::cout << std::endl;
}

bool Board::pickChecker(int pick, std::vector<int>& picked)
{
	for (int i : picked)
	{
		if (pick == i)
			return false;
	}
	return true;
}

bool Board::winChecker()
{
	if (board[0] == board[2] && board[2] == board[4] && board[2] != " ")
	{
		return true;
	}
	else if (board[6] == board[8] && board[8] == board[10] && board[8] != " ")
	{
		return true;
	}
	else if (board[12] == board[14] && board[14] == board[16] && board[14] != " ")
	{
		return true;
	}
	else if (board[0] == board[6] && board[6] == board[12] && board[6] != " ")
	{
		return true;
	}
	else if (board[2] == board[8] && board[8] == board[14] && board[8] != " ")
	{
		return true;
	}
	else if (board[4] == board[10] && board[10] == board[16] && board[10] != " ")
	{
		return true;
	}
	else if (board[0] == board[8] && board[8] == board[16] && board[8] != " ")
	{
		return true;
	}
	else if (board[4] == board[8] && board[8] == board[12] && board[8] != " ")
	{
		return true;
	}
	else
		return false;
}
