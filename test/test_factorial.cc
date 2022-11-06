#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, Factorial) {
  mynum::float_t x = mympf::create("3.1415926");
  mynum::float_t y = f::factorial(x);
  Check(y, "6.0");

  x = mympf::create("50");
  y = f::factorial(x);
  Check(y, "30414093201713378043612608166064768844377641568960512000000000000.0");

  x = mympf::create("20.3254321");
  y = f::factorial(x);
  Check(y, "2432902008176640000.0");
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}