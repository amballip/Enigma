#include "RotorManager.h"


RotorManager::RotorManager()
{
}

int RotorManager::chooseRotors(const std::vector<int>& selectionVec)
{
	for (size_t i = 0; i < selectionVec.size(); ++i)
	{
		switch (selectionVec[i])
		{
		case 1:
			m_rotorVec.push_back(&m_rotor1);
			m_rotor1.setRotorNo(selectionVec[i]);
			break;
		case 2:
			m_rotorVec.push_back(&m_rotor2);
			m_rotor2.setRotorNo(selectionVec[i]);
			break;
		case 3:
			m_rotorVec.push_back(&m_rotor3);
			m_rotor3.setRotorNo(selectionVec[i]);
			break;
		case 4:
			m_rotorVec.push_back(&m_rotor4);
			m_rotor4.setRotorNo(selectionVec[i]);
			break;
		case 5:
			m_rotorVec.push_back(&m_rotor5);
			m_rotor5.setRotorNo(selectionVec[i]);
			break;
		default:
			break;
		}
	}

	for (size_t i = 0; i < m_rotorVec.size()-1; ++i)
	{
		m_rotorVec[i]->setPreviousRotor(m_rotorVec[i + 1]);
	}
	return 0;
}

int RotorManager::setScrambleStrings(int rotorNo, const std::string& scrambleString)
{
	switch (rotorNo+1)
	{
	case 1:
		m_rotor1.setScrambleString(scrambleString);
		break;
	case 2:
		m_rotor2.setScrambleString(scrambleString);
		break;
	case 3:
		m_rotor3.setScrambleString(scrambleString);
		break;
	case 4:
		m_rotor4.setScrambleString(scrambleString);
		break;
	case 5:
		m_rotor5.setScrambleString(scrambleString);
		break;
	case 6:
		m_reflector.setScrambleString(scrambleString);
	default:
		break;
	}
	return 0;
}

int RotorManager::setInitialRotorPositions(const std::vector<int>& positionVec)
{
	for (size_t i = 0; i < positionVec.size(); ++i)
	{
		m_rotorVec[i]->setInitialPosition(positionVec[i]);
	}


	return 0;
}

char RotorManager::getLightChar(char indexChar)
{
	std::string logMessage;
	char temp = indexChar;
	
	temp = m_rotorVec[2]->getForwardChar(temp);
	temp = m_rotorVec[1]->getForwardChar(temp);
	temp = m_rotorVec[0]->getForwardChar(temp);
	temp = m_reflector.getChar(temp);

	temp = m_rotorVec[0]->getReverseChar(temp);
	temp = m_rotorVec[1]->getReverseChar(temp);
	temp = m_rotorVec[2]->getReverseChar(temp);

	return temp;

}

int RotorManager::setNotchPositions(int rotorNo, int notchPosition)
{
	switch (rotorNo+1)
	{
	case 1:
		m_rotor1.setNotchPosition(notchPosition);
		break;
	case 2:
		m_rotor2.setNotchPosition(notchPosition);
		break;
	case 3:
		m_rotor3.setNotchPosition(notchPosition);
		break;
	case 4:
		m_rotor4.setNotchPosition(notchPosition);
		break;
	case 5:
		m_rotor5.setNotchPosition(notchPosition);
		break;
	default:
		break;
	}

	return 0;
	
}
