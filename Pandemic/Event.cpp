#include <iostream>
#include <string>
#include "Event.h"

Event::Event(std::string n, std::string d) {
	name = n;
	description = d;
	type = "event";
}

Event::~Event(){}

std::string Event::getAttributes() {
	std::string atr = name + ":" + type + ":" + description;
	return atr;
}

std::string Event::getType()
{
	return type;
}

std::string Event::getName(){
	return name;
}

std::string Event::getDescription(){
	return description;
}
