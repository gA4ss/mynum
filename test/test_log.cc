#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, ln)
{
  mynum::float_t const_eps = mympf::create("0.00000000000001");
  mynum::float_t x = mympf::create(4, 0), y;
  y = f::ln(x, const_eps);
  // std::cout << "ln(4) = " << mympf::print_string(y) << std::endl;
  Check(y, "1.386294361119891");

  x = mympf::create(5, 0);
  y = f::ln(x, const_eps);
  // std::cout << "ln(5) = " << mympf::print_string(y) << std::endl;
  Check(y, "1.609437912434100");

  x = mympf::create("0.6");
  y = f::ln(x, const_eps);
  // std::cout << "ln(0.6) = " << mympf::print_string(y) << std::endl;
  Check(y, "-0.510826");

  x = mympf::create("0.4");
  y = f::ln(x, const_eps);
  // std::cout << "ln(0.6) = " << mympf::print_string(y) << std::endl;
  Check(y, "-0.916291");

  x = mympf::create("0.54267859843264381965986478329165983164783916589321648932658931");
  y = f::ln(x, const_eps);
  // std::cout << "ln(0.6) = " << mympf::print_string(y) << std::endl;
  Check(y, "-0.6112380340457363");
}

TEST(Float, log10)
{
  mynum::float_t const_eps = mympf::create("0.00000000000001");
  mynum::float_t x = mympf::create(4, 0), y;

  x = mympf::create("5");
  y = f::log10(x, const_eps);
  // std::cout << "ln(5) = " << mympf::print_string(y) << std::endl;
  Check(y, "0.69897000");

  x = mympf::create("0.6");
  y = f::log10(x, const_eps);
  // std::cout << "ln(5) = " << mympf::print_string(y) << std::endl;
  Check(y, "-0.221849");
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}