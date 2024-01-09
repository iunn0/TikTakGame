#include "Player.h"

int Player::pick = -1;
Board Player::boardG;

void Player::makeMove(std::function<void(int, std::vector<std::string>*)> func)
{
	if (Player::boardG.count != 5)
	{
		boardG.rightPos = false;
		while (!boardG.rightPos)
		{
			std::cin >> this->pick;
			while (this->pick < 1 || this->pick > 9)
			{
				std::cout << "Wrong position!" << std::endl << "Input position:" << std::endl;
				std::cin >> this->pick;
			}

			boardG.rightPos = Player::boardG.pickChecker(this->pick, Player::boardG.alreadyPicked);
			if (!boardG.rightPos)
				std::cout << "The position is already taken" << std::endl;
		}
		Player::boardG.alreadyPicked.push_back(this->pick);
		func(this->pick, &Player::boardG.board);
	}
	system("cls");
	boardG.displayBoard();
}
