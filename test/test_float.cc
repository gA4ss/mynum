#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/mynum.h>

using namespace mynum;

#define Check(x, y)  EXPECT_TRUE(mympf::ucmp(x, mympf::create(y)) == 0)
#define Check2(x, y) EXPECT_TRUE(mympf::ucmp(f::abs(mympf::sub((x), mympf::create((y)))),mympf::create("0.0001")) == -1)

TEST(Float, Trigonometric) {
  Float x = "0.5235987666666667", y;
  y = sin(x);
  EXPECT_TRUE(abs(y - "0.5") < "0.0001") << "y = " << y.str();

  y = cos(x);
  // std::cout << "cos(pi/6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.8660254037844387") < "0.0001") << "y = " << y.str();

  y = tan(x);
  // std::cout << "tan(pi/6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5773502691896257") < "0.0001") << "y = " << y.str();

  y = cot(x);
  // std::cout << "cot(pi/6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "1.7320508075688774") < "0.0001") << "y = " << y.str();

  y = sec(x);
  // std::cout << "sec(pi/6) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "1.154700538379252") < "0.0001") << "y = " << y.str();

  y = csc(x);
  EXPECT_TRUE(abs(y - "2.0000000000000004") < "0.0001") << "y = " << y.str();
  // std::cout << "csc(pi/6) = " << y.str() << std::endl;
}

// TEST(Float, ArcTrigonometric) {
//   Float x = "0.5", y;
//   y = arcsin(x);
//   // std::cout << "arcsin(0.5) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "0.8660254037844387";
//   y = arccos(x);
//   // std::cout << "arccos(0.8660254037844387) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "0.5773502691896257";
//   y = arctan(x);
//   // std::cout << "arccos(0.5773502691896257) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "1.7320508075688774";
//   y = arctan(x);
//   // std::cout << "arctan(1.7320508075688774) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "1.0472") < "0.0001") << "y = " << y.str();

//   x = "1.1547005383792515";
//   y = arcsec(x);
//   // std::cout << "arcsec(1.1547005383792515) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "2.0000000000000004";
//   y = arccsc(x);
//   // std::cout << "arccsc(2.0000000000000004) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "1.7320508075688774";
//   y = arccot(x);
//   // std::cout << "arccot(1.7320508075688774) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(abs(y) - "0.5235987666666667") < "0.0001") << "y = " << y.str();
// }

// TEST(Float, Hyperbolic) {
//   Float x = "0.5235987666666667", y;
//   y = sinh(x);
//   EXPECT_TRUE(abs(y - "0.547853") < "0.0001") << "y = " << y.str();

//   y = cosh(x);
//   EXPECT_TRUE(abs(y - "1.14024") < "0.0001") << "y = " << y.str();

//   y = tanh(x);
//   EXPECT_TRUE(abs(y - "0.480473") < "0.0001") << "y = " << y.str();

//   y = csch(x);
//   EXPECT_TRUE(abs(y - "1.82531") < "0.0001") << "y = " << y.str();

//   y = sech(x);
//   EXPECT_TRUE(abs(y - "0.87701") < "0.0001") << "y = " << y.str();

//   y = coth(x);
//   EXPECT_TRUE(abs(y - "2.08128") < "0.0001") << "y = " << y.str();
// }

// TEST(Float, ArcHyperbolic) {
//   Float x = "0.547853", y;
//   y = arcsinh(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "1.14024";
//   y = arccosh(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "0.480473";
//   y = arctanh(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "1.82531";
//   y = arccsch(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "0.87701";
//   y = arcsech(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

//   x = "2.08128";
//   y = arccoth(x);
//   EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();
// }

// TEST(Float, Fraction) {
//   Float x = "3.1415926";
//   std::pair<Integer, Integer> y = fraction(x);
//   EXPECT_TRUE(y.first == "15707963");
//   EXPECT_TRUE(y.second == "5000000");

//   x = "-3.1415926";
//   y = fraction(x);
//   EXPECT_TRUE(y.first == "-15707963");
//   EXPECT_TRUE(y.second == "5000000");

//   x = "0.75";
//   y = fraction(x);
//   EXPECT_TRUE(y.first == "3");
//   EXPECT_TRUE(y.second == "4");

//   x = "-0.5";
//   y = fraction(x);
//   EXPECT_TRUE(y.first == "-1");
//   EXPECT_TRUE(y.second == "2");
// }

// TEST(Float, Error) {
//   for (Float x = 0.00; x < 0.2; x += 0.01) {
//     std::cout << "erf(" << x << ") = " << erf(x) << "\t";
//     std::cout << "erfc(" << x << ") = " << erfc(x) << std::endl;
//   }
// }

// TEST(Float, Constant) {
//   Float pi = approximate_pi();
//   EXPECT_TRUE(abs(pi - "3.1415926") < "0.0001") << "pi = " << pi.str();
// }

int main(int argc, char* argv[]) {
  mynum::init();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}