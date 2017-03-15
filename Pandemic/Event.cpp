#include <iostream>
#include <string>
#include "Event.h"

Event::Event(std::string n, std::string d) {
	name = n;
	description = d;
}

Event::~Event(){}

void Event::getAttributes() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Description: " << description << std::endl;
}

std::string Event::getType()
{
	return name;
}
