#pragma once

#include<string>
#include<vector>
#include"Logger.h"
#include"UtilityFunctions.h"
#include<algorithm>
#include<fstream>

enum RotorNo
{
	rotor1,
	rotor2,
	rotor3,
	rotor4,
	rotor5,
	reflector

};


class ArgsParser
{
private:
	int m_argc;
	char** m_argv;
	std::string m_message;
	std::vector<int> m_selectionVec;
	std::vector<int> m_positionVec;
	std::string m_plugBoardString;
	std::string m_fileName;

	std::vector<std::string> m_rotorStringVec;
	std::vector<int> m_notchVec;

	enum logLevel m_logLevel;

	std::vector<std::string> m_unusedFlags;

	bool m_gotMessageFlag;
	bool m_gotSelectionFlag;
	bool m_gotPositionFlag;
	bool m_gotPlugBoardFlag;
	bool m_gotLogLevelFlag;


public:

	ArgsParser(std::string fileName);
	int parse();

	std::string getMessage();
	std::vector<int> getSelection();
	std::vector<int> getPosition();

	enum logLevel getLogLevel();
	std::string getPlugBoardString();


	bool validPlugBoardString();
	bool validLogLevel();
	bool validRotorString(RotorNo rotorNo);
	std::string getRotorString(RotorNo rotorNo);
	int getNotchPosition(RotorNo rotorNo);
	bool validNotchPosition(RotorNo rotorNo);

};

