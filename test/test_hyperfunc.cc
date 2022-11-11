#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)                                                                           \
  {                                                                                           \
    EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0) << #x " = " << mympf::print_string(x); \
  }
#define Check2(x, y)                                              \
  {                                                               \
    EXPECT_TRUE(mympf::ucmp(mympf::usub((x), mympf::create((y))), \
                            mympf::create("0.0001")) == -1)       \
        << #x " = " << mympf::print_string(x);                    \
  }

static const long double _r = M_PI / 180;
std::string R(long double d)
{
  long double r = _r * d;
  std::stringstream ss;
  ss << r;
  return ss.str();
}

TEST(Float, Sinh)
{
  mynum::float_t x, y;

  // x = mympf::create("-0.7986343967379184");
  // y = mympf::create("-0.7986355100472927");

  // mynum::float_t z = mympf::usub(x, y);
  // std::cout << "z = " << mympf::print_string(z) << std::endl;

  // (pi / 180) * 30 "0.5235987666666667"
  x = mympf::create("0.5235987666666667");
  y = f::sinh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.5478534637038506");

  x = mympf::create("1.0471975511965976");
  y = f::sinh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.2493670505239751");

  x = mympf::create("-2.2165681500327987");
  y = f::sinh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "-4.533402183291375");
}

TEST(Float, Cosh)
{
  // (pi / 180) * 30
  mynum::float_t x = mympf::create("0.5235987666666667");
  mynum::float_t y = f::cosh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.140238316183203");

  x = mympf::create("1.0471975511965976");
  y = f::cosh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.600286857702386");

  x = mympf::create("-2.2165681500327987");
  y = f::cosh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "4.6423846625921685");
}

TEST(Float, Tanh) {
  // (pi / 180) * 30
  mynum::float_t x, y;
  mynum::float_t z;

  x = mympf::create("0.5235987666666667");
  y = f::tanh(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.4804727712867233");

  x = mympf::create("1.0471975511965976");
  y = f::tanh(x);
  Check2(y, "0.7807144353592677");

  x = mympf::create("1.5533430342749532");
  y = f::tanh(x);
  Check2(y, "0.9143353957527748");
}

TEST(Float, Coth) {
  // (pi / 180) * 30
  mynum::float_t x = mympf::create("0.5235987666666667");
  mynum::float_t y = f::coth(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "2.081283393691518");

  x = mympf::create("1.0471975511965976");
  y = f::coth(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.2808780710450447");

  // 89
  x = mympf::create("1.5533430342749532");
  y = f::coth(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.0936905698337287");
}

TEST(Float, Sech) {
  // (pi / 180) * 30
  mynum::float_t x = mympf::create("0.5235987666666667");
  mynum::float_t y = f::sech(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.87701");

  x = mympf::create("1.0471975511965976");
  y = f::sech(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.624888");

  // 89
  x = mympf::create("1.5533430342749532");
  y = f::sech(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.404958");
}

TEST(Float, csch) {
  // (pi / 180) * 30
  mynum::float_t x = mympf::create("0.5235987666666667");
  mynum::float_t y = f::csch(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "1.82531");

  x = mympf::create("1.0471975511965976");
  y = f::csch(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.800405");

  // 89
  x = mympf::create("1.5533430342749532");
  y = f::csch(x);
  // std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.442898");
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}