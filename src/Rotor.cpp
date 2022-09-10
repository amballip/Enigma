#include "Rotor.h"

Rotor::Rotor():m_forwardScrambleMap(26,0),m_reverseScrambleMap(26,0)
{
	m_scrambleString="";
	m_rotorNo=0;
	m_notchPosition=0;
	m_initialPosition=0;
	m_charactersProcessed = 0;
}

std::string Rotor::getScrambledString()
{
	return m_scrambleString;
}

void Rotor::setInitialPosition(int position)
{
	m_initialPosition = position;

	rotateData(position);
	
}
void Rotor::rotateData(int position)
{
	std::rotate(m_forwardScrambleMap.begin(), m_forwardScrambleMap.begin() + m_initialPosition, m_forwardScrambleMap.end());

	for (size_t i = 0; i < m_forwardScrambleMap.size(); ++i)
	{
		m_reverseScrambleMap[charToIndex(m_forwardScrambleMap[i])] = i + 'a';
	}
}

char Rotor::getForwardChar(char indexChar)
{
	++m_charactersProcessed;

	if (m_rotorNo == 3)
	{
		rotateData(1);
	}
	else if ((m_rotorNo == 2 || m_rotorNo ==1) && m_previousRotor->isNotchReached())
	{
		rotateData(1);
	}

	char retVal = m_forwardScrambleMap[charToIndex(indexChar)];

	std::string message = std::string("getForwardChar from rotor no:") + std::to_string(m_rotorNo) + std::string(" Input:") + std::string(1, indexChar) + std::string(" Output:") + std::string(1, retVal);
	log(logLevel::trace,message);

	return retVal;
}

char Rotor::getReverseChar(char indexChar)
{
	char retVal = m_reverseScrambleMap[charToIndex(indexChar)];

	std::string message = std::string("getReverseChar from rotor no:") + std::to_string(m_rotorNo) + std::string(" Input:") + std::string(1, indexChar) + std::string(" Output:") + std::string(1, retVal);
	log(logLevel::trace,message);

	return retVal;
}
int Rotor::validateScrambleString(const std::string& scrambleString)
{
	return 0;
}

bool Rotor::setScrambleString(const std::string& scrambleString)
{
	m_scrambleString = scrambleString;
	if (validateScrambleString(scrambleString) != 0)
	{
		return false;
	}
	for (int i =0; i <scrambleString.size(); i++)
	{
		m_forwardScrambleMap[i] = scrambleString[i];
		m_reverseScrambleMap[charToIndex(scrambleString[i])] = i+'a';
	}

	return true;
}

void Rotor::setRotorNo(int rotorNo)
{
	m_rotorNo = rotorNo;
}

void Rotor::setNotchPosition(int position)
{
	m_notchPosition = position;
}

bool Rotor::isNotchReached()
{
	return ((m_charactersProcessed%26 +1)%m_notchPosition)==0;
}

void Rotor::setPreviousRotor(Rotor* rotor)
{
	m_previousRotor = rotor;
}

int Rotor::getRotorNo()
{
	return m_rotorNo;
}
