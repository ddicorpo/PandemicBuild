#pragma once
#include <iostream>
#include "Strategy.h"

class OptionFour_FlyResearch : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionFour_FlyResearch Execute()" << std::endl;
	}
};

