#pragma once
#include <iostream>
#include "Strategy.h"

class OptionSeven_Remove : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionSeven_Remove Execute()" << std::endl;
	}
};

