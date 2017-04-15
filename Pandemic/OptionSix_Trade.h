#pragma once
#include <iostream>
#include "Strategy.h"

class OptionSix_Trade : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionSix_Trade Execute()" << std::endl;
	}
};

