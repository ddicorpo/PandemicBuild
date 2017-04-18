#include "OptionFive_Cure.h"
#include <sstream>

OptionFive_Cure::OptionFive_Cure(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}


void OptionFive_Cure::execute()
{
	int blueCounter = 0;
	int redCounter = 0;
	int yellowCounter = 0;
	int blackCounter = 0;
	
	std::string duplicate;


	if (player->getCurrentCity()->getResearchStation() == true)
	{
		std::vector<PlayerCard*> cityCards;
		std::vector<PlayerCard*> hand = player->getHand();

		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i]->getType() == "city")
				cityCards.push_back(hand[i]);
		}
		
		for (int j = 0; j < cityCards.size(); j++)
		{
			std::istringstream ss;
			std::string item;
			ss.str(hand[j]->getAttributes());
			std::vector<std::string> temp;
			
			for (int k = 0; getline(ss, item, ':'); k++)
				temp.push_back(item);

			std::string colorOfCity = temp[2];

			if (colorOfCity == "blue")
				blueCounter++;

			if (colorOfCity == "black")
				blackCounter++;

			if (colorOfCity == "red")
				redCounter++;

			if (colorOfCity == "yellow")
				yellowCounter++;

		}
		


		std::cout << "Black cities: " << blackCounter << std::endl;
		std::cout << "Yellow cities: " << yellowCounter << std::endl;
		std::cout << "Blue cities: " << blueCounter << std::endl;
		std::cout << "Red cities: " << redCounter << std::endl;
		
		if (blackCounter >= 5)
		{
			// erase all cards with black color from player deck 
			// cure the black diseases
		}

		if (redCounter >= 5)
		{
			// erase all cards with black color from player deck 
			// cure the black diseases
		}

		if (blueCounter >= 5)
		{
			// erase all cards with black color from player deck 
			// cure the black diseases
		}

		if (yellowCounter >= 5)
		{
			// erase all cards with black color from player deck 
			// cure the black diseases
		}




	}
}