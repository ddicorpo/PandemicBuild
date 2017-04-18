#include "LogObserver.h"
#include <fstream>


LogObserver::LogObserver(){
}


LogObserver::~LogObserver(){
}

LogObserver::LogObserver(Log* s){
	_subject = s;
	_subject->Attach(this);
}

void LogObserver::Update() {
	std::ofstream logfile;
	logfile.open("log.txt",ios::app);
	logfile << _subject->log() << std::endl;

}
