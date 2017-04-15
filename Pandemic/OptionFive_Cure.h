#pragma once
#include <iostream>
#include "Strategy.h"

class OptionFive_Cure : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionFive_Cure Execute()" << std::endl;
	}
};

