#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class City : public PlayerCard {
public:
	City(std::string name, std::string color, int pop);
	~City();
	void getAttributes();
	std::string getCityName();	//for future development
	std::string getColor();		//for future development
	int getPop();				//for future development
	std::string getType();
private:
	std::string cityname;
	std::string citycolor;
	std::string type;
	int population;
};   