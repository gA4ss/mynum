#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y) EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))), mympf::create("0.0001")) == -1)

std::string print_fraction(mynum::fraction_t &x)
{
  return mympz::print_string(x.first) + "/" + mympz::print_string(x.second);
}

TEST(Float, FractionAdd)
{
  mynum::float_t x = mympf::create("0.5");
  mynum::float_t y = mympf::create("1.25");

  mynum::fraction_t _x = mynum::f::fraction(x);
  mynum::fraction_t _y = mynum::f::fraction(y);

  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  mynum::fraction_t z = mynum::f::add(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "7/4");

  x = mympf::create("-1");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::add(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "1/4");

  x = mympf::create("-5.5");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::add(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-17/4");

  x = mympf::create("-5.5");
  y = mympf::create("-2.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::add(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-31/4");
}

TEST(Float, FractionSub)
{
  mynum::float_t x = mympf::create("0.5");
  mynum::float_t y = mympf::create("1.25");

  mynum::fraction_t _x = mynum::f::fraction(x);
  mynum::fraction_t _y = mynum::f::fraction(y);

  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  mynum::fraction_t z = mynum::f::sub(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-3/4");

  x = mympf::create("-1");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::sub(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-9/4");

  x = mympf::create("-5.5");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::sub(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-27/4");

  x = mympf::create("-5.5");
  y = mympf::create("-2.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::sub(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-13/4");
}

TEST(Float, FractionMul)
{
  mynum::float_t x = mympf::create("0.5");
  mynum::float_t y = mympf::create("1.25");

  mynum::fraction_t _x = mynum::f::fraction(x);
  mynum::fraction_t _y = mynum::f::fraction(y);

  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  mynum::fraction_t z = mynum::f::mul(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "5/8");

  x = mympf::create("-1");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::mul(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-5/4");

  x = mympf::create("-5.5");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::mul(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-55/8");

  x = mympf::create("-5.5");
  y = mympf::create("-2.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::mul(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "99/8");
}

TEST(Float, FractionDiv)
{
  mynum::float_t x = mympf::create("0.5");
  mynum::float_t y = mympf::create("1.25");

  mynum::fraction_t _x = mynum::f::fraction(x);
  mynum::fraction_t _y = mynum::f::fraction(y);

  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  mynum::fraction_t z = mynum::f::div(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "2/5");

  x = mympf::create("-1");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::div(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-4/5");

  x = mympf::create("-5.5");
  y = mympf::create("1.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::div(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "-22/5");

  x = mympf::create("-5.5");
  y = mympf::create("-2.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  z = mynum::f::div(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(z).c_str(), "22/9");
}

TEST(Float, CommonDenominator)
{
  mynum::float_t x = mympf::create("0.5");
  mynum::float_t y = mympf::create("1.25");

  mynum::fraction_t _x = mynum::f::fraction(x);
  mynum::fraction_t _y = mynum::f::fraction(y);

  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  std::pair<fraction_t, fraction_t> xy = mynum::f::common_denominator(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(xy.first).c_str(), "2/4");
  EXPECT_STREQ(print_fraction(xy.second).c_str(), "5/4");

  x = mympf::create("-5.5");
  y = mympf::create("-2.25");

  _x = mynum::f::fraction(x);
  _y = mynum::f::fraction(y);
  // std::cout << "x = " << print_fraction(_x) << " "
  //           << "y = " << print_fraction(_y) << std::endl;

  xy = mynum::f::common_denominator(_x, _y);
  // std::cout << "z = " << print_fraction(z) << std::endl;
  EXPECT_STREQ(print_fraction(xy.first).c_str(), "-22/4");
  EXPECT_STREQ(print_fraction(xy.second).c_str(), "-9/4");
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}