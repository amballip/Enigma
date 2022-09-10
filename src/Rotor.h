#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include"Logger.h"
#include"UtilityFunctions.h"
#include<algorithm>

#define charToIndex(x) (x-'a')

class Rotor
{
private:
	std::vector<char> m_forwardScrambleMap;
	std::vector<char> m_reverseScrambleMap;
	std::string m_scrambleString;
	int m_rotorNo;
	int m_notchPosition;
	int m_initialPosition;
	int m_charactersProcessed;
	Rotor* m_previousRotor;

	int validateScrambleString(const std::string& scrambleString);
	
public:
	Rotor();
	bool setScrambleString(const std::string& scrambleString);
	void setRotorNo(int rotorNo);
	std::string getScrambledString();
	char getForwardChar(char indexChar);
	char getReverseChar(char indexChar);
	void setNotchPosition(int position);
	void setInitialPosition(int position);
	void rotateData(int position);
	bool isNotchReached();
	void setPreviousRotor(Rotor* rotor);
	int getRotorNo();
};

