#include <iostream>
#include "InfectionCard.h"
#include "GameManager.h"
#include "MapCity.h"

InfectionCard::InfectionCard(){}
InfectionCard::InfectionCard(std::string city, std::string colorCode) :city(city), colorCode(colorCode){}

std::string InfectionCard::getCity()
{
	return city;
}

std::string InfectionCard::getColor()
{
	return colorCode;
}