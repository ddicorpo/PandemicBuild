#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionSix_Trade : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionSix_Trade(Player*, std::vector<MapCity*>);
	void execute()
	{
		std::cout << "Called OptionSix_Trade Execute()" << std::endl;
	}
};

