#ifndef StringUtil_h
#define StringUtil_h

#include <string>

class StringUtil
{
public:
    static std::string head(const std::string& word);
    static std::string tail(const std::string& word);
    static std::string zeroPad(const std::string& text, unsigned int toLength);
    static std::string upperFront(const std::string& string);
};
#endif
