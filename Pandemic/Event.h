#pragma once
#include <iostream>
#include <string>
#include "PlayerCard.h"

class Event : public PlayerCard {
public:
	Event(std::string name, std::string desc);
	~Event();
	std::string getAttributes();
	std::string getType();
	std::string getName();
	std::string getDescription();
private:
	std::string name;
	std::string type;
	std::string description;
};