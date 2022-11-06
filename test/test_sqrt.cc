#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, Sqrt) {
  mynum::float_t const_eps = mympf::create("0.0000000000001");
  mynum::float_t x = mympf::create("2");
  mynum::float_t y = f::sqrt(x, const_eps);
  Check2(y, "1.4142135623730951");

  x = mympf::create("3.5");
  y = f::sqrt(x, const_eps);
  Check2(y, "1.8708286933869707");

  x = mympf::create("0.618");
  y = f::sqrt(x, const_eps);
  Check2(y, "0.7861297602813418");
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}