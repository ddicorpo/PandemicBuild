#pragma once
#include <iostream>
#include "Strategy.h"

class OptionDefault : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionDefault Execute()" << std::endl;
	}
};

