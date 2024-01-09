#include "Game.h"
#include "Player.h"
#include "BotPlayer.h"


void Game::mode()
{
	this->m = -1;
	std::cout << "Choose mode:" << std::endl << "0 - vs bot, 1 - vs local player" << std::endl;
	while (this->m != 0 && this->m != 1)
		std::cin >> this->m;
}

void Game::congratulation()
{
	if (p1)
		std::cout << "Player 1 won!" << std::endl;
	else if (p2)
		std::cout << "Player 2 won!" << std::endl;
	else if (botW)
		std::cout << "You lost!" << std::endl;
	else 
		std::cout << "Draw!" << std::endl;

	std::cout << "To exit type 1 :" << std::endl;
	int exit1 = 0;
	std::cin >> exit1;
}

void Game::botmode()
{
	this->lvl = -1;
	std::cout << "Choose lvl of bot: " << std::endl << "0 - easy, 1 - medium, 2 - unreal" << std::endl;
	while (this->lvl != 0 && this->lvl != 1 && this->lvl != 2)
		std::cin >> this->lvl;

	char frst[1];
	std::cout << "Choose who`s first: bot / player, type:" << std::endl;
	std::cin >> frst[0];

	while (frst[0] != 'p' && frst[0] != 'b')
	{
		std::cout << "Incorect. Choose who`s first: bot / player, type:" << std::endl;
		std::cin >> frst[0];
	}

	system("cls");
	Player player;
	BotPlayer botPl(lvl);

	if (frst[0] == 'p')
	{
		std::cout << "1 | 2 | 3\n----------\n4 | 5 | 6\n----------\n7 | 8 | 9\n";

		while (!end)
		{
			std::cout << std::endl << "Input position : " << std::endl;
			player.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.xses(p, map); });
			end = Player::boardG.winChecker();

			if (end)
			{
				p1 = true;
				break;
			}

			Player::boardG.count++;
			if (Player::boardG.count == 5)
				break;

			botPl.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.circles(p, map); });
			end = Player::boardG.winChecker();

			if (end)
			{
				botW = true;
				break;
			}
		}
	}
	else if (frst[0] == 'b')
	{
		std::cout << "1 | 2 | 3\n----------\n4 | 5 | 6\n----------\n7 | 8 | 9\n";

		while (!end)
		{
			Player::boardG.count++;

			botPl.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.xses(p, map); });			
			end = Player::boardG.winChecker();
			if (end)
			{
				botW = true;
				break;
			}

			std::cout << std::endl << "Input position : " << std::endl;
			player.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.circles(p, map); });
			end = Player::boardG.winChecker();
			if (end)
			{
				p1 = true;
				break;
			}
			if (Player::boardG.count == 5)
				break;
		}
	}
	congratulation();
}

void Game::local()
{
	system("cls");
	Player player1;
	Player player2;

	std::cout << "1 | 2 | 3\n----------\n4 | 5 | 6\n----------\n7 | 8 | 9\n";

	while (Player::boardG.count != 5 && !end)
	{
		std::cout << std::endl << "Input position 1 "<< std::endl;
		player1.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.xses(p, map); });
		end = Player::boardG.winChecker();

		if (end)
		{
			p1 = true;
			break;
		}
		Player::boardG.count++;
		if (Player::boardG.count == 5)
			break;

		std::cout << std::endl << "Input position 2 " << std::endl;
		player2.makeMove([&](int p, std::vector<std::string>* map) { Player::boardG.circles(p, map); });
		end = Player::boardG.winChecker();

		if (end)
		{
			p2 = true;
			break;
		}
	}

	congratulation();
}

void Game::startGame()
{
	this->mode();

	if (this->m == 0)
		this->botmode();
	else
		this->local();
	
}
