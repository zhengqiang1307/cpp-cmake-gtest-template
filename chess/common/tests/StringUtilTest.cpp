#include "gmock/gmock.h"
#include "chess/common/StringUtil.h"

using namespace std;
using namespace testing;

TEST(AString, AnswersHeadAsItsFirstLetter) { ASSERT_THAT(StringUtil::head("xyz"), Eq("x")); }

TEST(AString, AnswersHeadAsEmptyWhenEmpty) { ASSERT_THAT(StringUtil::head(""), Eq("")); }

TEST(AString, AnswersTailAsAllLettersAfterHead) { ASSERT_THAT(StringUtil::tail("xyz"), Eq("yz")); }

TEST(AString, AnswersTailAsEmptyWhenEmpty) { ASSERT_THAT(StringUtil::tail(""), Eq("")); }

TEST(AString, AnswersTailAsEmptyWhenContainsOnlyOneCharacter) { ASSERT_THAT(StringUtil::tail("X"), Eq("")); }
