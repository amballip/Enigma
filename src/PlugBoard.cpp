#include "PlugBoard.h"

PlugBoard::PlugBoard()
{
	for (char i = 'a'; i <= 'z'; ++i)
	{
		m_scrambleMap[i] = i;
	}
}

void PlugBoard::setScrambleString(const std::string& scrambleString)
{
	for (size_t i = 0; i < scrambleString.size(); i += 2)
	{
		m_scrambleMap[scrambleString[i]] = scrambleString[i + 1];
		m_scrambleMap[scrambleString[i + 1]] = scrambleString[i];
	}
}

char PlugBoard::getChar(char indexChar)
{
	std::string logMessage = std::string("PlugBoard::getChar Input:") + std::string(1, indexChar) + std::string(" Output:") + std::string(1, m_scrambleMap[indexChar]);
	log(logLevel::trace, logMessage);
	return m_scrambleMap[indexChar];
}

std::string PlugBoard::getScrambleString()
{
	return m_scrambleString;
}
