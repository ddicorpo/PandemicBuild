#pragma once
#include <string>
#include "PlayerCard.h"

class Epidemic : public PlayerCard{
public:
	Epidemic(std::string name);
	~Epidemic();
	std::string getAttributes();
	std::string getType();
private:
	std::string type;
	std::string atr;
	std::string name;
};