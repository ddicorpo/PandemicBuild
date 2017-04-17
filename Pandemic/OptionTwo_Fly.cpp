#include "OptionTwo_Fly.h"

OptionTwo_Fly::OptionTwo_Fly(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionTwo_Fly::execute(){
	std::vector<PlayerCard*> hand = player->getHand();
	std::vector<PlayerCard*> citycards;
	
	std::string cityname;
	for (int i = 0; i < hand.size(); i++){
		if (hand[i]->getType() == "city"){
			citycards.push_back(hand[i]);
		}
	}

	std::cout << "Fly to which city?" << std::endl;
	int option = 0;
	for (int i = 0; i < citycards.size(); i++){
		if (citycards[i]->getType() == "city"){
			std::cout << i + 1 << " : " << citycards[i]->getName() << std::endl;
		}
	}
	std::cin >> option;
	if (option > 0 && option <= citycards.size()){
		for (int i = 0; i < map.size(); i++){
			if (citycards[option - 1]->getName() == map[i]->getName()){
				player->setCurrentCity(map[i]);
				std::cout << "Player is now at: " << player->getCurrentCity()->getName() << std::endl;
				cityname = map[i]->getName();
				std::cout << cityname << std::endl;
				break;
			}
		}
		for (int i = 0; i < player->getHand().size(); i++){
			if (player->getHand()[i]->getName() == cityname){
				std::cout << player->getHand()[i]->getName();
				//  player->getHand().erase(player->getHand().begin() + i); // < --problem in the array
				break;
			}
		}
	}
}