#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, Exp) {
  mynum::float_t const_eps = mympf::create("0.0000000000001");
  // mynum::float_t x;
  // mynum::float_t e;

  mynum::float_t x = mympf::create("1");
  mynum::float_t e = f::exp(x, const_eps);
  // std::cout << "e = " << mympf::print_string(e) << std::endl;
  Check2(e, "2.71828182845904218449046031445");

  x = mympf::create("2");
  e = f::exp(x, const_eps);
  // std::cout << "e = " << mympf::print_string(e) << std::endl;
  Check2(e, "7.3890560989306459593739331417372");

  x = mympf::create("0.5");
  e = f::exp(x, const_eps);
  // std::cout << "e = " << mympf::print_string(e) << std::endl;
  Check2(e, "1.648721270700127422233701603645009");

  x = mympf::create("0.9");
  e = f::exp(x, const_eps);
  // std::cout << "e = " << mympf::print_string(e) << std::endl;
  Check2(e, "2.45960311115695");

  x = mympf::create("1.4484941211906903");
  e = f::exp(x, const_eps);
  // std::cout << "e = " << mympf::print_string(e) << std::endl;
  Check2(e, "4.256699612603923");
}


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}