#include "StringUtil.h"
#include "CharUtil.h"

std::string StringUtil::head(const std::string& word) { return word.substr(0, 1); }

std::string StringUtil::tail(const std::string& word)
{
    if (word.length() == 0)
        return "";
    return word.substr(1);
}

std::string StringUtil::zeroPad(const std::string& text, unsigned int toLength)
{
    auto zerosNeeded = toLength - text.length();
    return text + std::string(zerosNeeded, '0');
}

std::string StringUtil::upperFront(const std::string& string)
{
    return std::string(1, CharUtil::upper(string.front()));
}
