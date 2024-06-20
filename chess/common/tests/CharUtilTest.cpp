#include "gmock/gmock.h"

#include <string>
#include "chess/common/CharUtil.h"

using namespace std;
using namespace testing;

TEST(AChar, IsAVowelForSixSpecificLetters)
{
    ASSERT_TRUE(CharUtil::isVowel('A'));
    ASSERT_TRUE(CharUtil::isVowel('E'));
    ASSERT_TRUE(CharUtil::isVowel('I'));
    ASSERT_TRUE(CharUtil::isVowel('O'));
    ASSERT_TRUE(CharUtil::isVowel('U'));
    ASSERT_TRUE(CharUtil::isVowel('Y'));
}

TEST(AChar, IsAVowelForLowercaseLetters)
{
    ASSERT_TRUE(CharUtil::isVowel('a'));
    ASSERT_TRUE(CharUtil::isVowel('e'));
    ASSERT_TRUE(CharUtil::isVowel('i'));
    ASSERT_TRUE(CharUtil::isVowel('o'));
    ASSERT_TRUE(CharUtil::isVowel('u'));
    ASSERT_TRUE(CharUtil::isVowel('y'));
}

TEST(AChar, IsNotAVowelForAnyOtherCharacter) { ASSERT_FALSE(CharUtil::isVowel('b')); }

TEST(AChar, AnswersAppropriateUpperCaseLetter) { ASSERT_THAT(CharUtil::upper('a'), Eq('A')); }

TEST(AChar, HandlesAlreadyUppercasedLetters) { ASSERT_THAT(CharUtil::upper('B'), Eq('B')); }

TEST(AChar, IgnoresNonLettersWhenUppercasing) { ASSERT_THAT(CharUtil::upper('+'), Eq('+')); }

TEST(AChar, AnswersAppropriateLowerCaseLetter) { ASSERT_THAT(CharUtil::lower('A'), Eq('a')); }

TEST(AChar, HandlesAlreadyLowercased) { ASSERT_THAT(CharUtil::lower('b'), Eq('b')); }

TEST(AChar, IgnoresNonLettersWhenLowercasing) { ASSERT_THAT(CharUtil::lower('+'), Eq('+')); }
