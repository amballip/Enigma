#include "ArgsParser.h"

const std::string messageFlag = "-ms";
const std::string selectionFlag = "-rs";
const std::string positionFlag = "-rp";
const std::string logLevelFlag = "-ll";
const std::string plugBoardFlag = "-pb";
const std::string rotor1StringFlag = "-r1";
const std::string rotor2StringFlag = "-r2";
const std::string rotor3StringFlag = "-r3";
const std::string rotor4StringFlag = "-r4";
const std::string rotor5StringFlag = "-r5";
const std::string reflectorStringFlag = "-rl";
const std::string rotor1NotchFlag = "-n1";
const std::string rotor2NotchFlag = "-n2";
const std::string rotor3NotchFlag = "-n3";
const std::string rotor4NotchFlag = "-n4";
const std::string rotor5NotchFlag=  "-n5";


ArgsParser::ArgsParser(std::string fileName):m_rotorStringVec(6,""), m_notchVec(5,0)
{
	m_gotMessageFlag = false;
	m_gotSelectionFlag = false;
	m_gotPositionFlag = false;
	m_gotPlugBoardFlag = false;
	m_gotLogLevelFlag = false;
	m_fileName = fileName;
}

int ArgsParser::parse()
{
	std::ifstream file(m_fileName.c_str());


	std::string arg;
	while(getline(file,arg))
	{
		std::string flagString = arg.substr(0, 3);
		
		if (flagString == messageFlag)
		{
			m_message = arg.substr(4);

			if (UtilityFunctions::isMessageProper(m_message)!=0)
			{
				log(logLevel::error, "Message string not proper");
				break;
			}
			UtilityFunctions::convertToSmallCase(m_message);
			m_gotMessageFlag = true;
		}
		else if (flagString == selectionFlag)
		{
			int startingCharacterNo = 4;
			int firstCommaPosition = arg.find(',', startingCharacterNo);
			std::string pos1 = arg.substr(startingCharacterNo, firstCommaPosition - startingCharacterNo);

			int secondCommaPosition = arg.find(',', firstCommaPosition + 1);
			std::string pos2 = arg.substr(firstCommaPosition + 1, secondCommaPosition - firstCommaPosition-1);

			std::string pos3 = arg.substr(secondCommaPosition + 1);

			m_selectionVec = { std::stoi(pos1),std::stoi(pos2),std::stoi(pos3) };

			if (UtilityFunctions::isSelectionProper(m_selectionVec) != 0)
			{
				log(logLevel::error, "Selection vector not proper");
				break;
			}

			m_gotSelectionFlag = true;
			
		}
		else if (flagString == positionFlag)
		{
			int startingCharacterNo = 4;
			int firstCommaPosition = arg.find(',', startingCharacterNo);
			std::string pos1 = arg.substr(startingCharacterNo, firstCommaPosition - startingCharacterNo);

			int secondCommaPosition = arg.find(',', firstCommaPosition + 1);
			std::string pos2 = arg.substr(firstCommaPosition + 1, secondCommaPosition - firstCommaPosition - 1);

			std::string pos3 = arg.substr(secondCommaPosition + 1);

			m_positionVec = { std::stoi(pos1),std::stoi(pos2),std::stoi(pos3) };

			if (UtilityFunctions::isPositionProper(m_positionVec) != 0)
			{
				log(logLevel::error, "Position vector not proper");
				break;
			}
			m_gotPositionFlag = true;
		}
		else if (flagString == logLevelFlag)
		{
			std::string logLevel = arg.substr(4);
			if (logLevel == "trace")
			{
				m_logLevel = logLevel::trace;
				m_gotLogLevelFlag = true;
			}
			else if (logLevel == "debug")
			{
				m_logLevel = logLevel::debug;
				m_gotLogLevelFlag = true;
			}
			else if(logLevel == "error")
			{
				m_logLevel = logLevel::error;
				m_gotLogLevelFlag = true;
			}
		}
		else if (flagString == plugBoardFlag)
		{
			m_plugBoardString = arg.substr(4);
			m_plugBoardString.erase(std::remove(m_plugBoardString.begin(), m_plugBoardString.end(), ','), m_plugBoardString.end());
			if (UtilityFunctions::isPlugBoardStringProper(m_plugBoardString) != 0)
			{
				log(logLevel::error, "Plug board string not proper");
				break;
			}
			m_gotPlugBoardFlag = true;
		}
		else if (flagString == rotor1StringFlag)
		{
			m_rotorStringVec[rotor1] = arg.substr(4);
		}
		else if (flagString == rotor2StringFlag)
		{
			m_rotorStringVec[rotor2] = arg.substr(4);
		}
		else if (flagString == rotor3StringFlag)
		{
			m_rotorStringVec[rotor3] = arg.substr(4);
		}
		else if (flagString == rotor4StringFlag)
		{
			m_rotorStringVec[rotor4] = arg.substr(4);
		}
		else if (flagString == rotor5StringFlag)
		{
			m_rotorStringVec[rotor5] = arg.substr(4);

		}
		else if (flagString == reflectorStringFlag)
		{
			m_rotorStringVec[reflector] = arg.substr(4);
		}
		else if (flagString == rotor1NotchFlag)
		{
			m_notchVec[rotor1]= std::stoi(arg.substr(4));

		}
		else if (flagString == rotor2NotchFlag)
		{
			m_notchVec[rotor2] = std::stoi(arg.substr(4));
		}
		else if (flagString == rotor3NotchFlag)
		{
			m_notchVec[rotor3] = std::stoi(arg.substr(4));
		}
		else if (flagString == rotor4NotchFlag)
		{
			m_notchVec[rotor4] = std::stoi(arg.substr(4));
		}
		else if (flagString == rotor5NotchFlag)
		{
			m_notchVec[rotor5] = std::stoi(arg.substr(4));
		}
		else
		{
			m_unusedFlags.push_back(arg);
		}

	}

	if (!m_gotMessageFlag || !m_gotPositionFlag || !m_gotSelectionFlag)
	{
		return -1;
	}

	return 0;
}

enum logLevel ArgsParser::getLogLevel()
{
	return m_logLevel;
}

std::string ArgsParser::getMessage()
{
	return m_message;
}

std::vector<int> ArgsParser::getSelection()
{
	return m_selectionVec;
}

std::vector<int> ArgsParser::getPosition()
{
	return m_positionVec;
}

std::string ArgsParser::getPlugBoardString()
{
	return m_plugBoardString;
}

bool ArgsParser::validPlugBoardString()
{
	return m_gotPlugBoardFlag;
}

bool ArgsParser::validLogLevel()
{
	return m_gotLogLevelFlag;
}

bool ArgsParser::validRotorString(RotorNo rotorNo)
{
	return !m_rotorStringVec[rotorNo].empty();
}

std::string ArgsParser::getRotorString(RotorNo rotorNo)
{
	return m_rotorStringVec[rotorNo];
}

int ArgsParser::getNotchPosition(RotorNo rotorNo)
{
	return m_notchVec[rotorNo];
}

bool ArgsParser::validNotchPosition(RotorNo rotorNo)
{
	return m_notchVec[rotorNo]!=0;
}

