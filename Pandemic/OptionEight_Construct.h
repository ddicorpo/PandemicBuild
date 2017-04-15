#pragma once
#include <iostream>
#include "Strategy.h"

class OptionEight_Construct : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionEight_Construct Execute()" << std::endl;
	}
};

