#include "BotPlayer.h"

int randomLRUD()
{
	srand(static_cast<unsigned>(time(NULL)));
	int sw = 1 + rand() % 4;
	switch (sw)
	{
	case 1:
		return 2;
		break;
	case 2:
		return 6;
		break;
	case 3:
		return 10;
		break;
	case 4:
		return 14;
		break;
	}
}

bool BotPlayer::findWinningMove(int& move, std::vector<std::string>* map)
{
	for (int i = 1; i <= 9; ++i)
	{
		if (map->at((i - 1) * 2) == " ")
		{
			map->at((i - 1) * 2) = "O"; 
			if (boardG.winChecker())
			{
				move = i;
				map->at((i - 1) * 2) = " ";
				return true;
			}
			map->at((i - 1) * 2) = " ";
		}
	}

	return false;
}

bool BotPlayer::blockOpponentWinningMove(int& move, std::vector<std::string>* map)
{
	for (int i = 1; i <= 9; ++i)
	{
		if (map->at((i - 1) * 2) == " ")
		{
			map->at((i - 1) * 2) = "X"; 
			if (boardG.winChecker())
			{
				move = i;
				map->at((i - 1) * 2) = " "; 
				return true;
			}
			map->at((i - 1) * 2) = " ";
		}
	}

	return false;
}

void BotPlayer::random()
{
	srand(static_cast<unsigned>(time(NULL)));
	this->botPick = (1 + rand() % 9);
}

void BotPlayer::medium()
{
	int move = -1;
	srand(static_cast<unsigned>(time(NULL)));

	if (findWinningMove(move, &Player::boardG.board) && (1+ rand() % 3) != 3)
	{
		this->botPick = move;
		return;
	}

	if (blockOpponentWinningMove(move, &Player::boardG.board) && (1 + rand() % 3) != 2)
	{
		this->botPick = move;
		return;
	}

	if (Player::boardG.board[8] == " " && (1 + rand() % 2) == 1)
		move = 5;
	else if (Player::boardG.board[0] == " " && (1 + rand() % 2) == 1)
		move = 1;
	else if (Player::boardG.board[4] == " " && (1 + rand() % 2) == 1)
		move = 3;
	else if (Player::boardG.board[12] == " " && (1 + rand() % 2) == 1)
		move = 7;
	else if (Player::boardG.board[16] == " " && (1 + rand() % 2) == 1)
		move = 9;
	else
{
		move = randomLRUD();
		while(boardG.board[move] != " ")
			move = randomLRUD();

		move = move / 2 + 1;
	}

	this->botPick = move;
}

void BotPlayer::hard()
{
	int move = -1;
	srand(static_cast<unsigned>(time(NULL)));

	if (findWinningMove(move, &Player::boardG.board))
	{
		this->botPick = move;
		return;
	}

	if (blockOpponentWinningMove(move, &Player::boardG.board))
	{
		this->botPick = move;
		return;
	}

	if (Player::boardG.board[8] == " ")
		move = 5;
	else if (Player::boardG.board[0] == " ")
		move = 1;
	else if (Player::boardG.board[4] == " ")
		move = 3;
	else if (Player::boardG.board[12] == " ")
		move = 7;
	else if (Player::boardG.board[16] == " ")
		move = 9;
	else
	{
		move = randomLRUD();
		while(boardG.board[move] != " ")
			move = randomLRUD();

		move = move / 2 + 1;
	}

	this->botPick = move;
}

void BotPlayer::chooser()
{
	switch (lv)
	{
	case 0:
		random();
		break;
	case 1:
		medium();
		break;
	case 2:
		hard();
		break;
	}
}

void BotPlayer::makeMove(std::function<void(int, std::vector<std::string>*)> func)
{
	

	Player::boardG.rightPos = false;
	while (!boardG.rightPos)
	{
		this->chooser();
		boardG.rightPos = boardG.pickChecker(this->botPick, boardG.alreadyPicked);
	}
	system("cls");
	boardG.alreadyPicked.push_back(this->botPick);
	func(this->botPick, &boardG.board);
	
	boardG.displayBoard();
}
