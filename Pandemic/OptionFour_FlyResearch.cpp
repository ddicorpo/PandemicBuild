#include "OptionFour_FlyResearch.h"
#include "GameManager.h"

OptionFour_FlyResearch::OptionFour_FlyResearch(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionFour_FlyResearch::execute()
{
	std::vector<MapCity*> citiesWithResearchStation;
	std::cout << "Here are all the cities that contain research stations: " << std::endl;
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i]->getResearchStation() == true)
		{
			citiesWithResearchStation.push_back(map[i]);
			for (int j = 0; j < citiesWithResearchStation.size(); j++)
				std::cout << j + 1 << ") " << citiesWithResearchStation[j]->getName() << std::endl;
		}
			
	}

	int playerChoice; 
	std::cout << "Where would you like to go?" << std::endl; 
	std::cin >> playerChoice; 

	if (playerChoice > 0 && playerChoice <= citiesWithResearchStation.size())
	{
		player->setCurrentCity(citiesWithResearchStation[playerChoice - 1]);
		std::cout << player->getName() << " is now at: " << player->getCurrentCity()->getName() << std::endl;
	}
	else {
		std::cout << "Invalid input!";
		GameManager::Instance().setvalidaction(false);
	}
		
}