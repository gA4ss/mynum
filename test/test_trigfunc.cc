#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

static const long double _r = M_PI / 180;
std::string R(long double d)
{
  long double r = _r * d;
  std::stringstream ss;
  ss << r;
  return ss.str();
}

TEST(Float, Sin) {
  mynum::float_t const_eps = mympf::create("0.00000005");
  mynum::float_t x, y;

  // (pi / 180) * 30 "0.5235987666666667"
  x = mympf::create(R(30.0));
  y = f::sin(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.5");

  x = mympf::create(R(60.0));
  y = f::sin(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.8660254037844386");

  x = mympf::create(R(-127.0));
  y = f::sin(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "-0.7986355100472927");
}

TEST(Float, Cos) {
  mynum::float_t const_eps = mympf::create("0.0000000000001");

  // (pi / 180) * 30
  mynum::float_t x = mympf::create("0.5235987666666667");
  mynum::float_t y = f::cos(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.8660254037844387");

  x = mympf::create("1.0471975511965976");
  y = f::cos(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "0.5000000000000001");

  x = mympf::create("-2.2165681500327987");
  y = f::cos(x, const_eps);
  std::cout << "y = " << mympf::print_string(y) << std::endl;
  Check2(y, "-0.6018150231520484");
}

// TEST(Float, Tan) {
//   mynum::float_t const_eps = mympf::create("0.000001");

//   // (pi / 180) * 30
//   mynum::float_t x = mympf::create(R(30.0));
//   mynum::float_t y = f::tan(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "0.5773502691896257");

//   x = mympf::create(R(60.0));
//   y = f::tan(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "1.7320508075688767");

//   // 89
//   x = mympf::create(R(89.0));
//   y = f::tan(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "57.289961630759144");
// }

// TEST(Float, Cot) {
//   mynum::float_t const_eps = mympf::create("0.000001");

//   // (pi / 180) * 30
//   mynum::float_t x = mympf::create(R(30.0));
//   mynum::float_t y = f::cot(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "1.7320508075688774");

//   x = mympf::create(R(60.0));
//   y = f::cot(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "0.577350269189626");

//   // 89
//   x = mympf::create(R(89.0));
//   y = f::cot(x, const_eps);
//   std::cout << "y = " << mympf::print_string(y) << std::endl;
//   Check2(y, "0.017455064928217672");
// }

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}