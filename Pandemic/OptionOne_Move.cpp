#include "OptionOne_Move.h"
#include <vector>

OptionOne_Move::OptionOne_Move(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionOne_Move::execute()
{
	std::vector<MapCity*> neighbors = player->getCurrentCity()->getNeighbours();
	int option = 0;
	std::cout << "Which neighbor?" << std::endl;
	for (int i = 0; i < neighbors.size(); i++){
		std::cout << i + 1 << " : " << neighbors[i]->getName() << std::endl;
	}
	std::cin >> option;

	if (option > 0 && option <= neighbors.size()){
		player->setCurrentCity(neighbors[option - 1]);
	}

	std::cout << std::endl << "You moved to " << player->getCurrentCity()->getName() << std::endl;
}