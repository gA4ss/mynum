#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/float.h>

using namespace mynum;

TEST(Float, Pow) {
  Float m, n, exp;

  m = "5";
  exp = "3";
  n = pow(m, exp);
  EXPECT_TRUE(n == "125") << "n = " << n.str();

  m = "2";
  exp = "8";
  n = pow(m, exp);
  EXPECT_TRUE(n == "256") << "n = " << n.str();

  m = "2";
  exp = "64";
  n = pow(m, exp);
  EXPECT_TRUE(n == "18446744073709551616") << "n = " << n.str();

  m = "2";
  exp = "128";
  n = pow(m, exp);
  EXPECT_TRUE(n == "340282366920938463463374607431768211456") << "n = " << n.str();

  m = "5.3";
  exp = "4.7";
  n = pow(m, exp);
  EXPECT_TRUE(abs(n - "2535.692505986549") < "0.0001") << "n = " << n.str();

  m = "4.5";
  exp = "-3.14";
  n = pow(m, exp);
  EXPECT_TRUE(abs(n - "0.00889022") < "0.0001") << "n = " << n.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}