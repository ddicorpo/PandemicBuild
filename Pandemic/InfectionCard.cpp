#include <iostream>
#include "InfectionCard.h"
#include "GameManager.h"


InfectionCard::InfectionCard(std::string city, std::string colorCode) :city(city), colorCode(colorCode){};

void InfectionCard::infect()
{
	
		std::cout << city << " infected! 1 " << colorCode << " added to " << city << "." << std::endl;
		GameManager::Instance().updateCubes(colorCode, 1);
}