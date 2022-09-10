#include<iostream>
#include"RotorManager.h"
#include"Logger.h"
#include"ArgsParser.h"
#include"PlugBoard.h"

extern Logger logger;

int main(int argc, char* argv[])
{
	ArgsParser parser("input.txt");
	if (parser.parse() != 0)
	{
		return -1; // Atleast compulsary flags are not passed, So return
	}

	std::cout << "Input message:  " << parser.getMessage() << std::endl;

	if (parser.validLogLevel())
	{
		logger.setLogLevel(parser.getLogLevel());
	}
	else
	{
		logger.setLogLevel(logLevel::error);
	}
	

	RotorManager rotorManager;
	rotorManager.chooseRotors(parser.getSelection());


	std::vector<std::string> scrambleStringVec = { "kdwjarvylsgpnhboztiexqfmcu",  // Rotor 1
													"hdrsmvjezpqufixtbnwgocklay", // Rotor 2
													"dhymzjrxoqiawlkbupecgsfvnt", // Rotor 3
													"wjtpmruvcnqfaehlkyxobzdgis", // Rotor 4
													"ndwzhuiyepojvarxlkqcbmsftg", // Rotor 5
													"ueyvwtzlmfxdbcrhpqogajknsi"  // Reflector
	};

	std::vector<int> notchVec = { 1,1,1,1,1 };
	for (int rotorNo = rotor1; rotorNo <= reflector; ++rotorNo)
	{
		if (parser.validRotorString((RotorNo)rotorNo))
		{
			rotorManager.setScrambleStrings(rotorNo, parser.getRotorString((RotorNo)rotorNo));
		}
		else
		{
			rotorManager.setScrambleStrings(rotorNo, scrambleStringVec[rotorNo]);
		}
	}

	for (int rotorNo = rotor1; rotorNo <= rotor5; ++rotorNo)
	{
		if (parser.validNotchPosition((RotorNo)rotorNo))
		{
			rotorManager.setNotchPositions(rotorNo, parser.getNotchPosition((RotorNo)rotorNo));
		}
		else
		{
			rotorManager.setNotchPositions(rotorNo, notchVec[rotorNo]);
		}
	}

	
	rotorManager.setInitialRotorPositions(parser.getPosition()); /* choose initial rotor positions between 1 and 26*/


	PlugBoard plugBoard;
	if (parser.validPlugBoardString())
	{
		plugBoard.setScrambleString(parser.getPlugBoardString());
	}

	std::string modifiedMessage;
	char temp;
	for (size_t i = 0; i < parser.getMessage().size(); ++i)
	{
		temp = plugBoard.getChar(parser.getMessage()[i]);
		temp = rotorManager.getLightChar(temp);
		temp = plugBoard.getChar(temp);
		modifiedMessage.push_back(temp);
	}
	std::cout << "Output message: " << modifiedMessage << std::endl;

	return 0;
}


