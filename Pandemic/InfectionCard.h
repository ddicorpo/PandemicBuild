#pragma once
#include <string>

class InfectionCard
{

public:
	InfectionCard::InfectionCard();
	InfectionCard::InfectionCard(std::string city, std::string colorCode);

	std::string infect();

	std::string getCity();
	std::string getColor();

private:
	std::string colorCode;
	std::string city;

};



