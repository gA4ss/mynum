#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/numeric.h>

using namespace mynum;

TEST(Numeric, Create) {
  EXPECT_TRUE(is_nan(Numeric("nan")));
  EXPECT_TRUE(Numeric("inf") == "inf");
  EXPECT_TRUE(Numeric("-inf") == "-inf");
  EXPECT_TRUE("0" == Numeric("0"));
  EXPECT_TRUE(Numeric(".3414") == "0.3414");
  EXPECT_TRUE("123456789.123456789" == Numeric("123456789.123456789"));
  EXPECT_TRUE(Numeric("1844674407370955161518446744073709551615") == "1844674407370955161518446744073709551615");
}

TEST(Numeric, Compare) {
  Numeric m, n;

  m = "4.134";
  n = "5.02";
  EXPECT_TRUE(m != n);
  EXPECT_TRUE(m < n);

  -m;
  -n;
  EXPECT_TRUE(m > n);

  m = "5";
  n = "5.0";
  EXPECT_TRUE(m == n);

  m = "5";
  n = "inf";
  EXPECT_TRUE(m < n);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}