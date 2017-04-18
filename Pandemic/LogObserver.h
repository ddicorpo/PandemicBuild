#pragma once
#include "Observer.h"
#include "Log.h"

class LogObserver : public Observer
{
public:
	LogObserver();
	LogObserver(Log* s);
	~LogObserver();
	void Update();
private:
	Log* _subject;
};

