#pragma once
#include"Rotor.h"
#include"Reflector.h"
#include"Logger.h"
#include"UtilityFunctions.h"


class RotorManager
{
private:
	Rotor m_rotor1, m_rotor2, m_rotor3, m_rotor4, m_rotor5;
	Reflector m_reflector;
	std::vector<Rotor*> m_rotorVec;

public:
	RotorManager();
	int chooseRotors(const std::vector<int>& selectionVec);
	int setScrambleStrings(int rotorNo, const std::string& scrambleString);
	int setInitialRotorPositions(const std::vector<int>& positionVec);
	char getLightChar(char indexChar);
	int setNotchPositions(int rotorNo,int notchPosition);
};

