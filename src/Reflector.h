#pragma once

#include<string>
#include<unordered_map>
#include"Logger.h"

class Reflector
{
private:
	std::unordered_map<char,char> m_scrambleMap;
	int validateScrambleString(const std::string& scrambleString);

public:
	Reflector();
	bool setScrambleString(const std::string& scrambleString);
	char getChar(char indexChar);
};

