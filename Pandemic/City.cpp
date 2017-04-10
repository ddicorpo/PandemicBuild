#include <iostream>
#include <string>
#include "City.h"

City::City(std::string name, std::string color, int pop) {
	cityname = name;
	citycolor = color;
	population = pop;
	type = "city";
}

City::~City(){}

std::string City::getAttributes() {
	std::string atr = cityname + ":" + type + ":" + citycolor + ":" + std::to_string(population);
	return atr;
}

std::string City::getType()
{
	return type;
}

std::string City::getName(){
	return cityname;
}

int City::getPop(){
	return population;
}

std::string City::getColor(){
	return citycolor;
}





