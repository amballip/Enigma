#include "Logger.h"

Logger logger;

void log(logLevel level,std::string message)
{
	logger.log(level, message);

}

Logger::Logger()
{
}

void Logger::setLogLevel(logLevel level)
{
	m_logLevel = level;
}

void Logger::log(logLevel level,std::string message)
{
	if (level >= m_logLevel)
	{
		std::cout << message << std::endl;
	}

}
