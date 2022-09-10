#include "UtilityFunctions.h"

int UtilityFunctions::isMessageProper(const std::string& message)
{
    /*
        1. There should not be any number or special character in the string.
    */

    for (size_t i = 0; i < message.size(); ++i)
    {
        if (!isalpha(message[i]))
        {
            return -1;
        }
    }

    return 0;
}

int UtilityFunctions::isSelectionProper(const std::vector<int> selectionVec)
{
    /*
      1.Rotors should be between 1 and 5
      2.Rotors should not be repeated
    */

    for (int position : selectionVec)
    {
        if (position < 1 || position >5)
        {
            return -1;
        }
    }
    std::unordered_set<int> st(selectionVec.begin(), selectionVec.end());
    if (st.size() != selectionVec.size())
        return -1;

    return 0;
}

int UtilityFunctions::isPositionProper(const std::vector<int> positionVec)
{
    /*
      1. Valid rotor positions are from 1 to 26
     */

    for (int selection : positionVec)
    {
        if (selection < 1 || selection >26)
            return -1;
    }

    return 0;
  
}

int UtilityFunctions::isPlugBoardStringProper(const std::string& plugBoardString)
{
    /*
        1. Invalid if length is more than 26
        2. No characters should be repeated
    */

    if (plugBoardString.size() > 26)
    {
        return -1;
    }

    std::unordered_map<char,char> mp;

    for (size_t i = 0; i < plugBoardString.size(); i+=2)
    {
        if (mp.count(plugBoardString[i]) == 0)
        {
            mp.insert({ plugBoardString[i],plugBoardString[i + 1] });
            mp.insert({ plugBoardString[i+1],plugBoardString[i] });
        }
        else
        {
            return -1;
        }

    }
    return 0;
}

int UtilityFunctions::convertToSmallCase(std::string& message)
{
    for (size_t i = 0; i < message.size(); ++i)
    {
        message[i] = tolower(message[i]);
    }
    return 0;
}


char UtilityFunctions::getRotatedChar(int modificationValue,char indexChar)
{
    unsigned char inputVal = indexChar;

    inputVal = indexChar + modificationValue-1;

    if (inputVal > 'z')
    {
        inputVal -= 26;
    }
    return inputVal;
}
