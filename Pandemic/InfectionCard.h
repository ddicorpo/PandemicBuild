#pragma once
#include <string>

class InfectionCard
{

public:

	InfectionCard::InfectionCard(std::string city, std::string colorCode);

	void infect(); 

private:
	std::string colorCode;
	std::string city;

};



