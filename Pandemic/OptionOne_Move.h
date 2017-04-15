#pragma once
#include <iostream>
#include "Strategy.h"

class OptionOne_Move : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionOne_Move Execute()" << std::endl;
	}
};

