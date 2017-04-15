#pragma once
#include <iostream>
#include "Strategy.h"

class OptionThree_FlyAny : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionThree_FlyAny Execute()" << std::endl;
	}
};

