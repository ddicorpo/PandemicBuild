#include "Log.h"

Log::Log(){
}
Log::~Log(){
}

std::string Log::log(){
	return output;
}

std::string Log::setOutput(std::string output){
	this->output = output;
	Notify();
	return output;
}
