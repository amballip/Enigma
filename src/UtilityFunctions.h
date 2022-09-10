#pragma once
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

class UtilityFunctions
{
private:
public:
	static int isMessageProper(const std::string& message);
	static int isSelectionProper(const std::vector<int> selectionVec);
	static int isPositionProper(const std::vector<int> positionVec);
	static int isPlugBoardStringProper(const std::string& plugBoardString);
	static int convertToSmallCase(std::string& message);
	static char getRotatedChar(int modificationValue, char indexChar);
};

