#pragma once
#include "Subject.h"
#include <string>
class Log : public Subject
{
public:
	Log();
	~Log();
	std::string setOutput(std::string output);
	std::string log();
private:
	std::string output;

};

