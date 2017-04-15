#pragma once
#include <string>

class InfectionCard
{

public:

	InfectionCard::InfectionCard(std::string city, std::string colorCode);

	void infect(); 
	std::string getCity();


private:
	std::string colorCode;
	std::string city;

};



