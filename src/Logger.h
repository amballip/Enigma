#pragma once

#include<string>
#include<iostream>

enum logLevel { trace, debug, error };

class Logger
{
private:

	logLevel m_logLevel;
public:

	Logger();
	void setLogLevel(logLevel level);
	void log(logLevel level, std::string message);
};


void log(logLevel level,std::string message);

