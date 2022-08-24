#include <gtest/gtest.h>
#include "myfunctions.h"
#include <string>
#include <boost/algorithm/string.hpp>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, MyFunction)
{
  EXPECT_EQ(f(), 42);
}

TEST(HelloTest, BoostStringsToUpper)
{
  std::string str1("HeLlO WoRld!");
  boost::to_upper(str1); // str1=="HELLO WORLD!"
  EXPECT_EQ(str1, "HELLO WORLD!");
}
