#pragma once

#include<string>
#include<unordered_map>
#include"Logger.h"

class PlugBoard
{
private:
	std::unordered_map<char,char> m_scrambleMap;
	std::string m_scrambleString;
public:
	PlugBoard();
	void setScrambleString(const std::string& scrambleString);
	char getChar(char indexChar);
	std::string getScrambleString();
};

