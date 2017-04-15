#pragma once
#include <iostream>
#include "Strategy.h"

class OptionTwo_Fly : public Strategy
{
public:
	void execute()
	{
		std::cout << "Called OptionTwo_Fly Execute()" << std::endl;
	}
};

