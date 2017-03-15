#pragma once
#include <string>
#include "PlayerCard.h"

class Epidemic : public PlayerCard{
public:
	Epidemic();
	~Epidemic();
	void getAttributes();
	std::string getType();
private:
	std::string type;
};