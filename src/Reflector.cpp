#include "Reflector.h"

int Reflector::validateScrambleString(const std::string& scrambleString)
{
    return 0;
}

Reflector::Reflector()
{
}

bool Reflector::setScrambleString(const std::string& scrambleString)
{
    if (validateScrambleString(scrambleString) != 0)
    {
        return false;
    }

    for (size_t i = 0;i<scrambleString.size();i+=2)
    {
        m_scrambleMap[scrambleString[i]] = scrambleString[i + 1];
        m_scrambleMap[scrambleString[i+1]] = scrambleString[i];
    }

    return true;
}

char Reflector::getChar(char indexChar)
{
    std::string message = std::string("getChar from Mirror ") + std::string(" Input:") + std::string(1, indexChar) + std::string(" Output:") + std::string(1, m_scrambleMap[indexChar]);
    log(logLevel::trace,message);
    return m_scrambleMap[indexChar];
}
