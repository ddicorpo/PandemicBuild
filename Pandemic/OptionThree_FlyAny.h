#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionThree_FlyAny : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionThree_FlyAny(Player*, std::vector<MapCity*>);
	void execute()
	{
		std::cout << "Called OptionThree_FlyAny Execute()" << std::endl;
	}
};
