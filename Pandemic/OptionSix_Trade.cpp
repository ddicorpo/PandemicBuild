#include "OptionSix_Trade.h"

OptionSix_Trade::OptionSix_Trade(Player* player, std::vector<MapCity*> map)
{
	this->player = player;
	this->map = map;
}

void OptionSix_Trade::execute()
{
	std::cout << "Called OptionSix_Trade Execute()" << std::endl;
}
