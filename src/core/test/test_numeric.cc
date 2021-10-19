#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <mynum/core/numeric.h>

using namespace mynum::core;

TEST(Numeric, Create) {
  EXPECT_TRUE(is_nan(Numeric("nan")));
  EXPECT_TRUE(Numeric("inf") == "inf");
  EXPECT_TRUE(Numeric("-inf") == "-inf");
  EXPECT_TRUE("0" == Numeric("0"));
  EXPECT_TRUE(Numeric(".3414") == "0.3414");
  EXPECT_TRUE("123456789.123456789" == Numeric("123456789.123456789"));
  EXPECT_TRUE(Numeric("1844674407370955161518446744073709551615") == "1844674407370955161518446744073709551615");
}

TEST(Numeric, Add) {
  Numeric m,n,z;
  m = Numeric("3.1415926");
  n = Numeric("2.1532");
  z = m + n;
  EXPECT_TRUE(z == "5.2947926");

  m = Numeric("3.1415926");
  n = Numeric("-3.1415926");
  z = m + n;
  EXPECT_TRUE(z == "0") << " z == " << z.str();
}

TEST(Numeric, Sub) {
  Numeric m,n,z;
  m = Numeric("3.1415926");
  n = Numeric("-3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "6.2831852");

  m = Numeric("0");
  n = Numeric("3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "-3.1415926");

  m = Numeric("inf");
  n = Numeric("3.1415926");
  z = m - n;
  EXPECT_TRUE(z == "inf");

  m = Numeric("3.1415926");
  n = Numeric("inf");
  z = m - n;
  EXPECT_TRUE(z == "-inf");

  m = Numeric("3.1415926");
  n = Numeric("0");
  z = m - n;
  EXPECT_TRUE(z == "3.1415926");
}

TEST(Numeric, Mul) {
  Numeric m,n,z;
  m = Numeric("3.1415926");
  n = Numeric("-3.1415926");
  z = m * n;
  EXPECT_TRUE(z == "-9.86960406437476");

  m = Numeric("0");
  n = Numeric("3.1415926");
  z = m * n;
  EXPECT_TRUE(z == "0");

  m = Numeric("inf");
  z = m * "0";
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Numeric("-inf");
  z = "0" * m;
  EXPECT_TRUE(is_nan(z)) << "z = " << z.str();

  m = Numeric("1844674407370955161518446744073709551615");
  m *= "1844674407370955161518446744073709551615"; 
  EXPECT_TRUE(m == "3402823669209384634332867666227678774935636506223790760108426481119284349108225");
}

TEST(Numeric, Div) {
  Numeric m;
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
}

TEST(Numeric, DecimalsDiv) {
  // Numeric x = "0.1435475698776374";
  Numeric x = "0.1", y = "6", z;
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
}

TEST(Numeric, IDiv) {
  Numeric m,n,z;
  m = "1000";
  n = "2";
  z = m / n;
  EXPECT_TRUE(z == "500") << "z = " << z.str();

  m = Numeric("7");
  n = Numeric("3");
  z = m / n;
  EXPECT_TRUE(z == "2");

  m = Numeric("-7");
  n = Numeric("3");
  z = m / n;
  EXPECT_TRUE(z == "-3");

  m = Numeric("7");
  n = Numeric("-3");
  z = m / n;
  EXPECT_TRUE(z == "-3");

  m = Numeric("-7");
  n = Numeric("-3");
  z = m / n;
  EXPECT_TRUE(z == "2");

  m = Numeric("5");
  n = Numeric("11");
  z = m / n;
  EXPECT_TRUE(z == "0");

  m = Numeric("-5");
  n = Numeric("11");
  z = m / n;
  EXPECT_TRUE(z == "-1");

  m = Numeric("5");
  n = Numeric("-11");
  z = m / n;
  EXPECT_TRUE(z == "-1");

  m = Numeric("-5");
  n = Numeric("-11");
  z = m / n;
  EXPECT_TRUE(z == "0");
}

TEST(Numeric, Mod) {
  Numeric m,n,z;

  m = Numeric("inf");
  n = Numeric("3");
  z = m % n;
  EXPECT_TRUE(is_nan(z));

  m = Numeric("3");
  n = Numeric("inf");
  z = m % n;
  EXPECT_TRUE(z == "3");

  m = Numeric("7");
  n = Numeric("3");
  z = m % n;
  EXPECT_TRUE(z == "1");

  m = Numeric("-7");
  n = Numeric("3");
  z = m % n;
  EXPECT_TRUE(z == "2");

  m = Numeric("7");
  n = Numeric("-3");
  z = m % n;
  EXPECT_TRUE(z == "-2");

  m = Numeric("-7");
  n = Numeric("-3");
  z = m % n;
  EXPECT_TRUE(z == "-1");

  m = Numeric("5");
  n = Numeric("11");
  z = m % n;
  EXPECT_TRUE(z == "5");

  m = Numeric("-5");
  n = Numeric("11");
  z = m % n;
  EXPECT_TRUE(z == "6");

  m = Numeric("5");
  n = Numeric("-11");
  z = m % n;
  EXPECT_TRUE(z == "-6");

  m = Numeric("-5");
  n = Numeric("-11");
  z = m % n;
  EXPECT_TRUE(z == "-5");
}

TEST(Numeric, Round) {
  Numeric m, n;

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

TEST(Numeric, Shift) {
  Numeric m, n, b;

  m = "4";
  b = "5";
  n = m << b;
  EXPECT_TRUE(n == "128") << "n = " << n.str();

  n = m >> b;
  EXPECT_TRUE(n == "0") << "n = " << n.str();

  m = "1000";
  b = "100";
  n = m >> b;
  EXPECT_TRUE(n == "0") << "n = " << n.str();
}

TEST(Numeric, Compare) {
  Numeric m, n;

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

TEST(Numeric, Euclid) {
  Numeric m, n, z;
  std::pair<Numeric, Numeric> st;

  m = "10";
  n = "20";
  z = gcd(m, n);
  EXPECT_TRUE(z == "10") << "z = " << z.str();

  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "10";
  n = "20";
  z = lcm(m, n);
  EXPECT_TRUE(z == "20") << "z = " << z.str();

  m = "100";
  n = "25";
  z = gcd(m, n);
  EXPECT_TRUE(z == "25") << "z = " << z.str();

  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "14532";
  n = "451";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "144";
  n = "8";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "8";
  n = "144";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) << "s = " << st.first.str() << " " << "t = " << st.second.str();

  m = "-5";
  n = "15";
  z = gcd(m, n);
  st = extended_euclidean(m, n);
  EXPECT_TRUE(z == st.first * m + st.second * n) <<"gcd = " << z.str() << " "
                                                 << "s = " << st.first.str() << " " << "t = " << st.second.str();
}

TEST(Numeric, Factorial) {
  Numeric m, n;

  m = "5";
  n = factorial(m);
  EXPECT_TRUE(n == "120") << "n = " << n.str();

  m = "15";
  n = factorial(m);
  EXPECT_TRUE(n == "1307674368000") << "n = " << n.str();

  m = "25";
  n = factorial(m);
  EXPECT_TRUE(n == "15511210043330985984000000") << "n = " << n.str();
}

TEST(Numeric, Pow) {
  Numeric m, n, exp;

  m = "5";
  exp = "3";
  n = pow(m, exp);
  EXPECT_TRUE(n == "125") << "n = " << n.str();

  m = "2";
  exp = "8";
  n = pow(m, exp);
  EXPECT_TRUE(n == "256") << "n = " << n.str();

  m = "2";
  exp = "64";
  n = pow(m, exp);
  EXPECT_TRUE(n == "18446744073709551616") << "n = " << n.str();

  m = "2";
  exp = "128";
  n = pow(m, exp);
  EXPECT_TRUE(n == "340282366920938463463374607431768211456") << "n = " << n.str();
}

// TEST(Numeric, BernoulliNumbers) {
//   Numeric x = "0", y;
//   for (int i = 0; i < 9; i++) {
//     y = bernoulli_numbers(x);
//     std::cout << "bernoulli(" << x.str() << ") = " << y.str() << std::endl;
//     x++;
//   }
// }

TEST(Numeric, Trigonometric) {
  Numeric x = "0.5235987666666667", y;
  y = sin(x);
  EXPECT_TRUE(y - "0.5" < "0.0001") << "y = " << y.str();

  y = cos(x);
  EXPECT_TRUE(y - "0.8660254037844387" < "0.0001") << "y = " << y.str();

  y = tan(x);
  EXPECT_TRUE(y - "0.5773502691896257" < "0.0001") << "y = " << y.str();

  y = cot(x);
  EXPECT_TRUE(y - "0.5773502691896257" < "0.0001") << "y = " << y.str();
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}