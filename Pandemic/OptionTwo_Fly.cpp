#include "OptionTwo_Fly.h"

OptionTwo_Fly::OptionTwo_Fly(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionTwo_Fly::execute(){

	std::vector<PlayerCard*> hand = player->getHand();
	int option;
	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->getType() == "city"){
			std::cout << i + 1 << " : " << hand[i]->getName() << std::endl;
		}
	}
	std::cout << "Where to move? Picking a city will dicard your card." << std::endl;
	std::cin >> option;
	if (option > 0 && option <= hand.size()){
		for (int i = 0; i < map.size(); i++){
			if (hand[option - 1]->getName() == map[i]->getName()){
				player->setCurrentCity(map[i]);
				std::cout << "Player is now at: " << player->getCurrentCity()->getName() << std::endl;
				break;
			}
		}
		hand.erase(hand.begin() + (option-1));
		player->setHand(hand);
	}
}