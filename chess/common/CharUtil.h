#pragma once

#include <string>

namespace CharUtil
{
char lower(char ch) { return static_cast<char>(std::tolower(static_cast<unsigned char>(ch))); }

char upper(char ch) { return static_cast<char>(std::toupper(static_cast<unsigned char>(ch))); }

bool isVowel(char letter) { return std::string("aeiouy").find(lower(letter)) != std::string::npos; }

} // namespace CharUtil