#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionSeven_Remove : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionSeven_Remove(Player*, std::vector<MapCity*>);
	void execute();
	//{
	//	std::cout << "Called OptionSeven_Remove Execute()" << std::endl;
	//}
};

