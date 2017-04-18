#include "OptionTen_Save.h"

#include <vector>


OptionTen_Save::OptionTen_Save(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionTen_Save::execute()
{
}