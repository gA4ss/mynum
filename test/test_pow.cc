#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, Pow) {
  mynum::float_t m, n, e;

  m = mympf::create("5.7");
  e = mympf::create("4.7");
  n = f::pow(m, e);
  // std::cout << "n = " << mympf::print_string(n) << std::endl;
  Check2(n, "3569.5364548037956");

  m = mympf::create("5");
  e = mympf::create("0.9");
  n = f::pow(m, e);
  // std::cout << "n = " << mympf::print_string(n) << std::endl;
  // EXPECT_TRUE(abs(n - "2535.692505986549") < "0.0001") << "n = " << n.str();
  Check2(n, "4.256699612603923");

  m = mympf::create("4.5");
  e = mympf::create("-3.14");
  n = f::pow(m, e);
  // EXPECT_TRUE(abs(n - "2535.692505986549") < "0.0001") << "n = " << n.str();
  Check2(n, "0.00889022");

  m = mympf::create("5");
  e = mympf::create("3");
  n = f::pow(m, e);
  Check(n, "125");

  m = mympf::create("2");
  e = mympf::create("8");
  n = f::pow(m, e);
  Check(n, "256");

  m = mympf::create("2");
  e = mympf::create("64");
  n = f::pow(m, e);
  Check(n, "18446744073709551616");

  m = mympf::create("2");
  e = mympf::create("128");
  n = f::pow(m, e);
  Check(n, "340282366920938463463374607431768211456");
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}