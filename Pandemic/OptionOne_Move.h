#pragma once
#include <iostream>
#include "Strategy.h"
#include "Player.h"
#include "MapCity.h"
#include <vector>

class OptionOne_Move : public Strategy
{
private:
	Player* player;
	std::vector<MapCity*> map;
public:
	OptionOne_Move(Player*, std::vector<MapCity*>);
	void execute();
};

