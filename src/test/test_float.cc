#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/float.h>
#include <mynum/constant.h>

using namespace mynum;

TEST(Float, Create) {
  EXPECT_TRUE(is_nan(Float("nan")));
  EXPECT_TRUE(Float("inf") == "inf");
  EXPECT_TRUE(Float("-inf") == "-inf");
  EXPECT_TRUE("0" == Float("0"));
  EXPECT_TRUE(Float(".3414") == "0.3414");
  EXPECT_TRUE(Float("0.0333333333333333") == "0.0333333333333333");
  EXPECT_TRUE("123456789.123456789" == Float("123456789.123456789"));
  EXPECT_TRUE(Float("1844674407370955161518446744073709551615") == "1844674407370955161518446744073709551615");
  EXPECT_TRUE(Float(3.1415926) == 3.1415926);
  EXPECT_TRUE(Float(1.618) == 1.618);
  EXPECT_TRUE(Float(-4567.789120431) == -4567.789120431);
  // Float n;
  // std::cin >> n;
  // std::cout << n << std::endl;
}

TEST(Float, Add) {
  Float m,n,z;
  m = Float("3.1415926");
  n = Float("2.1532");
  z = m + n;
  EXPECT_TRUE(z == "5.2947926");

  z++;
  EXPECT_TRUE(z == "6.2947926") << "z = " << z;

  z += 1;
  EXPECT_TRUE(z == "7.2947926") << "z = " << z;

  z -= 1.0;
  EXPECT_TRUE(z == "6.2947926") << "z = " << z;

  m = Float("3.1415926");
  n = Float("-3.1415926");
  z = m + n;
  EXPECT_TRUE(z == "0") << " z == " << z.str();
}

TEST(Float, Sub) {
  Float m,n,z;
  m = Float("3.1415926");
  n = Float("-3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "6.2831852");

  m = Float("0");
  n = Float("3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "-3.1415926");

  m = Float("inf");
  n = Float("3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "inf");

  m = Float("3.1415926");
  n = Float("inf");
  z = m - n;
  EXPECT_TRUE(z == "-inf");

  m = Float("3.1415926");
  n = Float("0");
  z = m - n;
  EXPECT_TRUE(z == "3.1415926");
}

TEST(Float, Mul) {
  Float m,n,z;
  m = Float("3.1415926");
  n = Float("-3.1415926");
  z = m * n;
  EXPECT_TRUE(z == "-9.86960406437476");

  m = Float("0");
  n = Float("3.1415926");
  z = m * n;
  EXPECT_TRUE(z == "0");

  m = Float("inf");
  z = m * "0";
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Float("-inf");
  z = "0" * m;
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Float("1844674407370955161518446744073709551615");
  m *= "1844674407370955161518446744073709551615"; 
  EXPECT_TRUE(m == "3402823669209384634332867666227678774935636506223790760108426481119284349108225");
}

TEST(Float, Div) {
  Float m;
  m = "7";
  m /= "inf";
  EXPECT_TRUE(m == "0.0");

  m = "inf";
  m /= "7";
  EXPECT_TRUE(m == "inf");

  m = "-inf";
  m /= "7";
  EXPECT_TRUE(m == "-inf");

  m = "inf";
  m /= "-inf";
  EXPECT_TRUE(is_nan(m));

  m = "0";
  m /= "7";
  EXPECT_TRUE(m == "0");

  m = "0";
  m /= "inf";
  EXPECT_TRUE(m == "0");

  m = "4.0000000000000000";
  m /= "2";
  EXPECT_TRUE(m == "2");
}

TEST(Float, DecimalsDiv) {
  // Float x = "0.1435475698776374";
  Float x = "0.1", y = "6", z;
  z = div(x, y);
  EXPECT_TRUE(z - "0.016666666666666666" < "0.0001") << "z = " << z.str();
  // std::cout << "0.1 / 6 = " << z.str() << std::endl;

  x = "1";
  y = "0.6";
  z = div(x, y);
  EXPECT_TRUE(z - "1.6666666666666667" < "0.0001") << "z = " << z.str();
  // std::cout << "1 / 0.6 = "  << z.str() << std::endl;

  x = "0.1";
  y = "0.6";
  z = div(x, y);
  EXPECT_TRUE(z - "0.16666666666666669" < "0.0001") << "z = " << z.str();
  // std::cout << "0.1 / 0.6 = "  << z.str() << std::endl;

  x = "1";
  y = "6";
  z = div(x, y);
  EXPECT_TRUE(z - "0.16666666666666666" < "0.0001") << "z = " << z.str();
  // std::cout << "1 / 6 = "  << z.str() << std::endl;

  x = "1";
  y = "6.0";
  z = div(x, y);
  EXPECT_TRUE(z - "0.16666666666666666" < "0.0001") << "z = " << z.str();

  x = "10.3";
  y = "10.1";
  z = div(x, y);
  EXPECT_TRUE(z - "1.0198019801980198" < "0.0001") << "z = " << z.str();
}

TEST(Float, Mod) {
  Float m,n,z;

  m = Float("inf");
  n = Float("3");
  z = m % n;
  EXPECT_TRUE(is_nan(z));

  m = Float("3");
  n = Float("inf");
  z = m % n;
  EXPECT_TRUE(z == "3");

  m = Float("7");
  n = Float("3");
  z = m % n;
  EXPECT_TRUE(z == "1");

  m = Float("-7");
  n = Float("3");
  z = m % n;
  EXPECT_TRUE(z == "2");

  m = Float("7");
  n = Float("-3");
  z = m % n;
  EXPECT_TRUE(z == "-2");

  m = Float("-7");
  n = Float("-3");
  z = m % n;
  EXPECT_TRUE(z == "-1");

  m = Float("5");
  n = Float("11");
  z = m % n;
  EXPECT_TRUE(z == "5");

  m = Float("-5");
  n = Float("11");
  z = m % n;
  EXPECT_TRUE(z == "6");

  m = Float("5");
  n = Float("-11");
  z = m % n;
  EXPECT_TRUE(z == "-6");

  m = Float("-5");
  n = Float("-11");
  z = m % n;
  EXPECT_TRUE(z == "-5");

  // --------------------

  m = Float("5.3");
  n = Float("10");
  z = m % n;
  EXPECT_TRUE(z == "5.3");

  m = Float("-5.3");
  n = Float("10");
  z = m % n;
  EXPECT_TRUE(z == "4.7");

  m = Float("5.3");
  n = Float("-10");
  z = m % n;
  EXPECT_TRUE(z == "-4.7");

  m = Float("-5.3");
  n = Float("-10");
  z = m % n;
  EXPECT_TRUE(z == "-5.3");

  // ---------------------

  m = Float("5.3");
  n = Float("3");
  z = m % n;
  EXPECT_TRUE(z == "2.3");

  m = Float("-5.3");
  n = Float("3");
  z = m % n;
  EXPECT_TRUE(z == "0.7");

  m = Float("5.3");
  n = Float("-3");
  z = m % n;
  EXPECT_TRUE(z == "-0.7");

  m = Float("-5.3");
  n = Float("-3");
  z = m % n;
  EXPECT_TRUE(z == "-2.3");
}

TEST(Float, Round) {
  Float m, n;

  m = "4.5";
  n = round(m);
  EXPECT_TRUE(n == "4");

  m = "5.5";
  n = round(m);
  EXPECT_TRUE(n == "6");

  m = "-6.5";
  n = round(m);
  EXPECT_TRUE(n == "-6");

  m = "-3.5";
  n = round(m);
  EXPECT_TRUE(n == "-4") << "n = " << n.str();

  // ------------------------------------

  m = "3.1415926";
  n = round(m, 0);
  EXPECT_TRUE(n == "3") << "n = " << n.str();

  n = round(m, 1);
  EXPECT_TRUE(n == "3.1") << "n = " << n.str();

  n = round(m, 2);
  EXPECT_TRUE(n == "3.14") << "n = " << n.str();

  n = round(m, 3);
  EXPECT_TRUE(n == "3.142") << "n = " << n.str();

  n = round(m, 4);
  EXPECT_TRUE(n == "3.1416") << "n = " << n.str();

  n = round(m, 5);
  EXPECT_TRUE(n == "3.14159") << "n = " << n.str();

  n = round(m, 6);
  EXPECT_TRUE(n == "3.141593") << "n = " << n.str();

  n = round(m, 7);
  EXPECT_TRUE(n == "3.1415926") << "n = " << n.str();

  n = round(m, 8);
  EXPECT_TRUE(n == "3.1415926") << "n = " << n.str();
}

TEST(Float, Compare) {
  Float m, n;

  m = "4.134";
  n = "5.02";
  EXPECT_TRUE(m != n);
  EXPECT_TRUE(m < n);

  -m;
  -n;
  EXPECT_TRUE(m > n);

  m = "5";
  n = "5.0";
  EXPECT_TRUE(m == n);

  m = "5";
  n = "inf";
  EXPECT_TRUE(m < n);
}

TEST(Float, Sqrt) {
  Float m, n;

  m = "2";
  n = sqrt(m, "0.0000000000000001");
  EXPECT_TRUE(abs(n - "1.414213562373095") <= "0.000001") << "n = " << n.str();

  m = "3";
  n = sqrt(m, "0.0000000000000001");
  EXPECT_TRUE(abs(n - "1.732050807568877") <= "0.000001") << "n = " << n.str();

  m = "4";
  n = sqrt(m, "0.0000000000000001");
  EXPECT_TRUE(abs(n - "2") <= "0.000001") << "n = " << n.str();

  m = "5.3";
  n = sqrt(m, "0.0000000000000001");
  EXPECT_TRUE(abs(n - "2.30217") <= "0.0001") << "n = " << n.str();

  m = "3.1415926";
  n = sqrt(m, "0.0000000000000001");
  EXPECT_TRUE(abs(n - "1.77245") <= "0.0001") << "n = " << n.str();
}

// TEST(Float, Pow) {
//   Float m, n, exp;

//   m = "5";
//   exp = "3";
//   n = pow(m, exp);
//   EXPECT_TRUE(n == "125") << "n = " << n.str();

//   m = "2";
//   exp = "8";
//   n = pow(m, exp);
//   EXPECT_TRUE(n == "256") << "n = " << n.str();

//   m = "2";
//   exp = "64";
//   n = pow(m, exp);
//   EXPECT_TRUE(n == "18446744073709551616") << "n = " << n.str();

//   m = "2";
//   exp = "128";
//   n = pow(m, exp);
//   EXPECT_TRUE(n == "340282366920938463463374607431768211456") << "n = " << n.str();

//   m = "5.3";
//   exp = "4.7";
//   n = pow(m, exp);
//   EXPECT_TRUE(abs(n - "2535.692505986549") < "0.0001") << "n = " << n.str();

//   m = "4.5";
//   exp = "-3.14";
//   n = pow(m, exp);
//   EXPECT_TRUE(abs(n - "0.00889022") < "0.0001") << "n = " << n.str();
// }

TEST(Float, Exponential) {
  Float x = "1", y;
  y = exp(x);
  // std::cout << "exp(1) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "2.71828182846") < "0.0001") << "y = " << y.str();

  x = "1.45";
  y = exp(x);
  // std::cout << "exp(1.45) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "4.26311") < "0.0001") << "y = " << y.str();
}

// TEST(Float, Logarithmic) {
//   Float x = "4", y;
//   y = ln(x);
//   // std::cout << "ln(4) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "1.386294361119891") < "0.0001") << "y = " << y.str();
  
//   x = "5";
//   y = ln(x);
//   // std::cout << "ln(5) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "1.609437912434100") < "0.0001") << "y = " << y.str();

//   x = "0.6";
//   y = ln(x);
//   // std::cout << "ln(0.6) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "-0.510826") < "0.0001") << "y = " << y.str();

//   x = "0.4";
//   y = ln(x);
//   // std::cout << "ln(0.4) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "-0.916291") < "0.0001") << "y = " << y.str();

//   x = "5";
//   y = log10(x);
//   // std::cout << "ln(5) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "0.69897000") < "0.0001") << "y = " << y.str();

//   x = "0.6";
//   y = log10(x);
//   // std::cout << "ln(0.6) = " << y.str() << std::endl;
//   EXPECT_TRUE(abs(y - "-0.221849") < "0.0001") << "y = " << y.str();
// }

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

TEST(Float, ArcTrigonometric) {
  Float x = "0.5", y;
  y = arcsin(x);
  // std::cout << "arcsin(0.5) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "0.8660254037844387";
  y = arccos(x);
  // std::cout << "arccos(0.8660254037844387) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "0.5773502691896257";
  y = arctan(x);
  // std::cout << "arccos(0.5773502691896257) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "1.7320508075688774";
  y = arctan(x);
  // std::cout << "arctan(1.7320508075688774) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "1.0472") < "0.0001") << "y = " << y.str();

  x = "1.1547005383792515";
  y = arcsec(x);
  // std::cout << "arcsec(1.1547005383792515) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "2.0000000000000004";
  y = arccsc(x);
  // std::cout << "arccsc(2.0000000000000004) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "1.7320508075688774";
  y = arccot(x);
  // std::cout << "arccot(1.7320508075688774) = " << y.str() << std::endl;
  EXPECT_TRUE(abs(abs(y) - "0.5235987666666667") < "0.0001") << "y = " << y.str();
}

TEST(Float, Hyperbolic) {
  Float x = "0.5235987666666667", y;
  y = sinh(x);
  EXPECT_TRUE(abs(y - "0.547853") < "0.0001") << "y = " << y.str();

  y = cosh(x);
  EXPECT_TRUE(abs(y - "1.14024") < "0.0001") << "y = " << y.str();

  y = tanh(x);
  EXPECT_TRUE(abs(y - "0.480473") < "0.0001") << "y = " << y.str();

  y = csch(x);
  EXPECT_TRUE(abs(y - "1.82531") < "0.0001") << "y = " << y.str();

  y = sech(x);
  EXPECT_TRUE(abs(y - "0.87701") < "0.0001") << "y = " << y.str();

  y = coth(x);
  EXPECT_TRUE(abs(y - "2.08128") < "0.0001") << "y = " << y.str();
}

TEST(Float, ArcHyperbolic) {
  Float x = "0.547853", y;
  y = arcsinh(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "1.14024";
  y = arccosh(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "0.480473";
  y = arctanh(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "1.82531";
  y = arccsch(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "0.87701";
  y = arcsech(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();

  x = "2.08128";
  y = arccoth(x);
  EXPECT_TRUE(abs(y - "0.5235987666666667") < "0.0001") << "y = " << y.str();
}

TEST(Float, Fraction) {
  Float x = "3.1415926";
  std::pair<Integer, Integer> y = fraction(x);
  EXPECT_TRUE(y.first == "15707963");
  EXPECT_TRUE(y.second == "5000000");

  x = "-3.1415926";
  y = fraction(x);
  EXPECT_TRUE(y.first == "-15707963");
  EXPECT_TRUE(y.second == "5000000");

  x = "0.75";
  y = fraction(x);
  EXPECT_TRUE(y.first == "3");
  EXPECT_TRUE(y.second == "4");

  x = "-0.5";
  y = fraction(x);
  EXPECT_TRUE(y.first == "-1");
  EXPECT_TRUE(y.second == "2");
}

TEST(Float, Error) {
  for (Float x = 0.00; x < 0.2; x += 0.01) {
    std::cout << "erf(" << x << ") = " << erf(x) << "\t";
    std::cout << "erfc(" << x << ") = " << erfc(x) << std::endl;
  }
}

TEST(Float, Constant) {
  // Float pi = approximate_pi();
  // EXPECT_TRUE(abs(pi - "3.1415926") < "0.0001") << "pi = " << pi.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}