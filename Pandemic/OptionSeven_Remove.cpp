#include "OptionSeven_Remove.h"

OptionSeven_Remove::OptionSeven_Remove(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}


void OptionSeven_Remove::execute()
{
	if (player->getCurrentCity()->getAllCubes() == 0)
	{
		std::cout << "No cubes to remove!";
	}

	else
	{

		player->getCurrentCity()->displayCubes();
		std::cout << "Which cube do you want to remove?" << std::endl;
		int playerChoice;
		std::cout << "Enter number here: ";
		std::cin >> playerChoice;
		std::cout << std::endl;

		switch (playerChoice)
		{
		case 1:
			if (player->getCurrentCity()->getBlackCubes() == 0)
			{
				std::cout << "No more black cubes! Pick again: " << std::endl;
				std::cin >> playerChoice;
			}

			else
				player->getCurrentCity()->removeBlackCube();

		case 2:
			if (player->getCurrentCity()->getBlueCubes() == 0)
			{
				std::cout << "No more blue cubes! Pick again: " << std::endl;
				std::cin >> playerChoice;
			}

			else
				player->getCurrentCity()->removeBlueCube();

		case 3:
			if (player->getCurrentCity()->getRedCubes() == 0)
			{
				std::cout << "No more red cubes! Pick again: " << std::endl;
				std::cin >> playerChoice;
			}

			else
				player->getCurrentCity()->removeRedCube();

		case 4:
			if (player->getCurrentCity()->getYellowCubes() == 0)
			{
				std::cout << "No more yellow cubes! Pick again: " << std::endl;
				std::cin >> playerChoice;
			}

			else
				player->getCurrentCity()->removeYellowCube();
		}
	}
}