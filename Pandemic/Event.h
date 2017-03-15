#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class Event : public PlayerCard {
public:
	Event(std::string name, std::string desc);
	~Event();
	void getAttributes();
	std::string getType();
private:
	std::string name;
	//std::string type;
	std::string description;
};