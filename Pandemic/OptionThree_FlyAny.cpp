#include "OptionThree_FlyAny.h"
#include <vector>

OptionThree_FlyAny::OptionThree_FlyAny(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;

}

void OptionThree_FlyAny::execute()
{
	std::map<std::string, std::vector<MapCity*>> regions;

	for (int i = 0; i < map.size(); i++){
		if (map[i]->getRegion() == "NorthAmerica"){
			regions["NorthAmerica"].push_back(map[i]);
		}
		else if (map[i]->getRegion() == "SouthAmerica"){
			regions["SouthAmerica"].push_back(map[i]);
		}
		else if (map[i]->getRegion() == "Europe"){
			regions["Europe"].push_back(map[i]);
		}
		else if (map[i]->getRegion() == "Asia"){
			regions["Asia"].push_back(map[i]);
		}
		else if (map[i]->getRegion() == "PacificRim"){
			regions["PacificRim"].push_back(map[i]);
		}
	}

	bool cardlocationmatch = false;
	int index;
	std::vector<PlayerCard*> hand = player->getHand();

	for (int i = 0; i < hand.size(); i++){
		if (player->getCurrentCity()->getName() == hand[i]->getName()){
			cardlocationmatch = true;
			index = i;
		}
	}

	if (cardlocationmatch == true){
		std::cout << "Move to which region" << std::endl;
		int option1;
		int r = 1;
		for (std::map<std::string, std::vector<MapCity*>>::iterator it = regions.begin(); it != regions.end(); ++it) {
			std::cout << r << " : " << it->first << std::endl;
			r++;
		}
		std::cin >> option1;

		int option2;
		if (option1 == 1){
			std::cout << "Move to which city?" << std::endl;
			for (int i = 0; i < regions["Asia"].size(); i++){
				std::cout << i + 1 << regions["Asia"][i]->getName() << std::endl;
			}
			std::cin >> option2;
			player->setCurrentCity(regions["Asia"][option2-1]);
			hand.erase(hand.begin() + index);
		}
		else if (option1 == 2){
			std::cout << "Move to which city?" << std::endl;
			for (int i = 0; i < regions["Europe"].size(); i++){
				std::cout << i + 1 << regions["Europe"][i]->getName() << std::endl;
			}
			std::cin >> option2;
			player->setCurrentCity(regions["Europe"][option2 - 1]);
			hand.erase(hand.begin() + index);
		}
		else if (option1 == 3){
			std::cout << "Move to which city?" << std::endl;
			for (int i = 0; i < regions["NorthAmerica"].size(); i++){
				std::cout << i + 1 << regions["NorthAmerica"][i]->getName() << std::endl;
			}
			std::cin >> option2;
			player->setCurrentCity(regions["NorthAmerica"][option2 - 1]);
			hand.erase(hand.begin() + index);
		}
		else if (option1 == 4){
			std::cout << "Move to which city?" << std::endl;
			for (int i = 0; i < regions["PacificRim"].size(); i++){
				std::cout << i + 1 << regions["PacificRim"][i]->getName() << std::endl;
			}
			std::cin >> option2;
			player->setCurrentCity(regions["PacificRim"][option2 - 1]);
			hand.erase(hand.begin() + index);
		}
		else if (option1 == 5){
			std::cout << "Move to which city?" << std::endl;
			for (int i = 0; i < regions["SouthAmerica"].size(); i++){
				std::cout << i + 1 << regions["SouthAmerica"][i]->getName() << std::endl;
			}
			std::cin >> option2;
			player->setCurrentCity(regions["SouthAmerica"][option2 - 1]);
			hand.erase(hand.begin() + index);
		}
	}
	else {
		std::cout << "This option is invalid" << std::endl;
	}

		player->setHand(hand);

}